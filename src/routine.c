/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:48:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/25 15:59:49 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thinking(t_program *p)
{
	print_time_stamp(p->philo, "is thinking");
}

static void	eating(t_program *p)
{
	// Take forks
	pthread_mutex_lock(p->philo->left_fork);
	print_time_stamp(p, p->philo, "has taken a fork");
	pthread_mutex_lock(p->philo->right_fork);
	print_time_stamp(p, p->philo, "has taken a fork");

	// Start eating
	print_time_stamp(p, p->philo, "is eating");
	pthread_mutex_lock(&p->lock);
	//p->philo->eating = 1;
	p->philo->last_eaten = get_current_time();
	p->eat_times++;
	pthread_mutex_unlock(&p->lock);

	// Sleep for time_to_eat 
	ft_usleep(p, p->time_to_eat);

	// Release forks
	//p->philo->eating = 0;
	pthread_mutex_unlock(p->philo->left_fork);
	pthread_mutex_unlock(p->philo->right_fork);
}

static void	sleeping(t_program *p)
{
	print_time_stamp(p, p->philo, "is sleeping");
	ft_usleep(p, p->time_to_sleep);
}

// dies if does not eat within a certain amount of time
void	died(t_program *p)
{
	long long	starved;
	
	p->philo->last_eaten = p->philo->start_time + p->time_to_eat;
	starved = get_current_time() - p->philo->last_eaten;
	if (starved > p->time_to_die)
	{
		p->philo->died = 1;
		print_time_stamp(p->philo, "died\n");
	}
}

// void *(*start_routine) (void *)
// A pointer to the function that the new thread will start executing. 
//This function should take a single void * argument and return a void *.
void	*start_routine(void *arg)
{
	t_program	*p;

	p = (t_program *)arg;
	while (p->eat_times > 0 || p->philo->died != 1)
	{
		thinking(p);
		eating(p);
		sleeping(p);
	}
	return (NULL);
}

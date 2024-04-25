/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:48:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/25 16:00:30 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thinking(t_philo *p)
{
	print_time_stamp(p, "is thinking");
}

static void	eating(t_philo *p)
{
	// Take forks
	pthread_mutex_lock(p->left_fork);
	print_time_stamp(p, "has taken left fork");
	pthread_mutex_lock(p->right_fork);
	print_time_stamp(p, "has taken right fork");

	// Start eating
	print_time_stamp(p, "is eating");

	//p->philo->eating = 1;

	// Sleep for time_to_eat
	ft_usleep(p->program->time_to_eat);

	p->last_eaten = get_current_time();

	// Release forks
	//p->philo->eating = 0;
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

static void	sleeping(t_philo *p)
{
	print_time_stamp(p, "is sleeping");
	ft_usleep(p->program->time_to_sleep);
}

// dies if does not eat within a certain amount of time
void	check_if_died(t_philo *p)
{
	if (get_current_time() - p->last_eaten > p->program->time_to_die)
	{
		p->died = 1;
		print_time_stamp(p, "died\n");
	}
}

// void *(*start_routine) (void *)
// A pointer to the function that the new thread will start executing. 
//This function should take a single void * argument and return a void *.
void	*start_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while ((p->program->eat_times == 0 || p->times_eaten < p->program->eat_times) || p->died != 1)
	{
		thinking(p);
		eating(p);
		sleeping(p);
		check_if_died(p);
	}
	return (NULL);
}

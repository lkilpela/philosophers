/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:48:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/05/02 09:11:54 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thinking(t_philo *philo)
{
	print_time_mutex(philo, CYAN "is thinking" NC);
}

static void	eating(t_philo *philo)
{
	// Take forks
	pthread_mutex_lock(philo->right_fork);
	
	print_time_mutex(philo, GREEN "has taken a fork" NC);
	if (philo->program->num_of_philos == 1)
	{
		ft_usleep(philo->program->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_time_mutex(philo, GREEN "has taken a fork" NC);	
	if (!check_if_died(philo))
	{
		// Start eating
		pthread_mutex_lock(&philo->program->lock);
		print_time_mutex(philo, "is eating");
		philo->last_ate = get_current_time();
		philo->times_eaten++;
		pthread_mutex_unlock(&philo->program->lock);

		// Sleep for time_to_eat 
		ft_usleep(philo->program->time_to_eat);
	}
	// Release forks
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	sleeping(t_philo *philo)
{
	print_time_mutex(philo, GREY "is sleeping" NC);
	ft_usleep(philo->program->time_to_sleep);
}

static int	philo_should_continue(t_philo *philo)
{
	return ((philo->program->num_times_to_eat == 0 
		|| philo->times_eaten < philo->program->num_times_to_eat)
		&& philo->died != 1);
}

// void *(*start_routine) (void *)
// A pointer to the function that the new thread will start executing. 
//This function should take a single void * argument and return a void *.
void	*start_routine(void *arg)
{
	t_philo	*philo;	

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(50);
	while (philo_should_continue(philo))
	{
		thinking(philo);
		eating(philo);
		if (!check_if_died(philo))
			sleeping(philo);
	}
	return (NULL);
}

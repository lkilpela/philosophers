/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:48:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/29 10:19:25 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thinking(t_philo *philo)
{
	print_time_stamp(philo, CYAN "is thinking" NC);
}

static void	eating(t_philo *philo)
{
	// Take forks
	pthread_mutex_lock(philo->left_fork);
	print_time_stamp(philo, GREEN "has taken a left fork" NC);
	pthread_mutex_lock(philo->right_fork);
	print_time_stamp(philo, GREEN "has taken a right fork" NC);

	if (!check_if_died(philo))
	{
		// Start eating
		print_time_stamp(philo, BLUE "is eating" NC);	
		// Sleep for time_to_eat 
		ft_usleep(philo->program->time_to_eat);
		philo->last_ate = get_current_time();
		philo->times_eaten++;
	}

	// Release forks
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	sleeping(t_philo *philo)
{
	print_time_stamp(philo, GREY "is sleeping" NC);
	ft_usleep(philo->program->time_to_sleep);
}

static int	philo_should_continue(t_philo *philo)
{
	return ((philo->program->eat_times == 0 
		|| philo->times_eaten < philo->program->eat_times)
		&& philo->died != 1);
}

// void *(*start_routine) (void *)
// A pointer to the function that the new thread will start executing. 
//This function should take a single void * argument and return a void *.
void	*start_routine(void *arg)
{
	t_philo	*philo;	

	philo = (t_philo *)arg;
	
	philo->last_ate = get_current_time();
	if (philo->program->num_of_philos == 1)
	{
		ft_usleep(philo->program->time_to_die);
		check_if_died(philo);
		return (NULL);
	}
	while (philo_should_continue(philo))
	{
		thinking(philo);
		eating(philo);
		if (!check_if_died(philo))
			sleeping(philo);
	}
	return (NULL);
}

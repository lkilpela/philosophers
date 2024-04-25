/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:48:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/25 13:12:48 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	
}

void	sleeping(t_philo *philo)
{
	
}

void	eating(t_philo *philo)
{
    philo->last_meal = get_time();
}
// dies if does not eat within a certain amount of time
void	died(t_philo *philo, int time_to_die)
{
	long long	starved;

	starved = get_time() - philo->last_meal;
	if (starved > time_to_die)
	{
		print_time_stamp(philo, "died\n");
	}
}

// void *(*start_routine) (void *)
// A pointer to the function that the new thread will start executing. 
//This function should take a single void * argument and return a void *.

void *start_routine(void *arg)
{
    t_philo *philo;

	philo = (t_philo *)arg;
	while(1)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}
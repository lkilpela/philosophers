/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:02:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/26 08:54:30 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// dies if does not eat within a certain amount of time
void	check_if_died(t_philo *philo)
{
	long long starved;

	starved = get_current_time() - philo->last_eaten;
	if (starved >= philo->program->time_to_die)
	{
		philo->died = 1;
		print_time_stamp(philo, "died\n");
		pthread_mutex_lock(&philo->program->lock);
		philo->program->quit = 1;
		pthread_mutex_unlock(&philo->program->lock);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:02:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/29 14:06:00 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// dies if does not eat within a certain amount of time
// if too much time has passed since philo's last ate & no eating again -> dead
int	check_if_died(t_philo *philo)
{
	if (!philo->died)
	{
		if (get_current_time() >= philo->last_ate
			+ philo->program->time_to_die)
		{
			pthread_mutex_lock(&philo->program->lock);
			philo->died = 1;
			pthread_mutex_unlock(&philo->program->lock);
			print_time_mutex(philo, RED "died" NC);
		}
	}
	return (philo->died);
}

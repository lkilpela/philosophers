/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:02:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/29 15:49:04 by lkilpela         ###   ########.fr       */
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
			philo->died = 1;
			print_time_mutex(philo, RED "died" NC);
		}
	}
	return (philo->died);
}


void	*monitor(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	while (1)
	{
		if (check_if_died(philo) == 1)
			break;
	}
	return (NULL);
}

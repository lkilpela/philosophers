/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:02:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/26 15:05:30 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// dies if does not eat within a certain amount of time
int	check_if_died(t_philo *philo)
{
	long long starved;

	if (!philo->died)
	{
		starved = get_current_time() - philo->last_eaten;
		//printf("get_current_time: %lld\n - last_eatean: %lld\n", get_current_time() - philo->start_time, philo->last_eaten - philo->start_time);
		if (starved >= philo->program->time_to_die)
		{
			//printf("starved: %lldms\n time_to_die: %lld\n", starved, philo->program->time_to_die);
			philo->died = 1;
			print_time_stamp(philo, "died");
			
		}
	}
	return (philo->died);
}

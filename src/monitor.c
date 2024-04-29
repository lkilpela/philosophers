/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:02:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/29 19:32:00 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// dies if does not eat within a certain amount of time
// if too much time has passed since philo's last ate & no eating again -> dead
int	check_if_died(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->program->lock);
	if (!philo->died)
	{
		if (get_current_time() >= philo->last_ate
			+ philo->program->time_to_die)
		{
			philo->died = 1;
			print_time(philo, RED "died" NC);
		}
	}
	dead = philo->died;
	pthread_mutex_unlock(&philo->program->lock);
	return (dead);
}

void	dead_monitor(t_program *p)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < p->num_of_philos)
		{
			if (check_if_died(&p->philos[i]) == 1)
				break ;
			i++;
		}
	}
}

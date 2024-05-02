/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:02:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/05/02 15:04:40 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// dies if does not eat within a certain amount of time
// if too much time has passed since philo's last ate & no eating again -> dead
int	check_if_died(t_philo *philo)
{
	int	quit;
	int	enough_eating;

	pthread_mutex_lock(&philo->program->lock);
	enough_eating = philo->program->num_times_to_eat
		&& philo->times_eaten >= philo->program->num_times_to_eat;
	if (!philo->died && !enough_eating)
	{
		if (get_current_time() >= philo->last_ate
			+ philo->program->time_to_die)
		{
			print_time(philo, RED "died" NC);
			philo->died = 1;
		}
	}
	quit = philo->died || enough_eating;
	pthread_mutex_unlock(&philo->program->lock);
	return (quit);
}

int	dead(t_program *p)
{
	int	i;

	i = 0;
	while (i < p->num_of_philos)
	{
		if (check_if_died(&p->philos[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	dead_monitor(t_program *p)
{
	int	i;

	i = 0;
	while (1)
	{
		if (dead(p))
			break ;
	}
	if (!p->num_times_to_eat)
	{
		pthread_mutex_lock(&p->lock);
		while (i < p->num_of_philos)
		{
			p->philos[i].died = 1;
			i++;
		}
		pthread_mutex_unlock(&p->lock);
	}
}
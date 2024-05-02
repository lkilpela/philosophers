/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:02:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/05/02 16:07:03 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// checks if a philosopher has died or has eaten enough times
// if too much time has passed since philo's last ate & no eating again -> dead
// enough_eating: true if num_times_to_eat is non-zero
// & times_eaten >= num_times_to_eat
int	check_philo_status(t_philo *philo)
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

static int	any_philo_died(t_program *p)
{
	int	i;

	i = 0;
	while (i < p->num_of_philos)
	{
		if (check_philo_status(&p->philos[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

// checking if any philosopher has died 
// and stopping the simulation if a philosopher has died
void	monitor_philos(t_program *p)
{
	int	i;

	i = 0;
	while (1)
	{
		if (any_philo_died(p))
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

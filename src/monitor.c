/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:02:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/05/02 09:33:16 by lkilpela         ###   ########.fr       */
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
			print_time_mutex(philo, RED "died" NC);
			philo->died = 1;
		}
	}
	dead = philo->died;
	pthread_mutex_unlock(&philo->program->lock);
	return (dead);
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
	pthread_mutex_lock(&p->lock);
	while (i < p->num_of_philos)
	{
		p->philos[i].died = 1;
		i++;
	}
	pthread_mutex_unlock(&p->lock);
}

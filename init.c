/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:22:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 15:33:02 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_program(t_program *p, int ac, char **av)
{
	p->num_of_philos = ft_atoi(av[1]);
	p->time_to_die = ft_atoi(av[2]);
	p->time_to_eat = ft_atoi(av[3]);
	p->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		p->philo->eat_times = 0;
	else
	{
		p->philo->eat_times = ft_atoi(av[5]);
		if (p->philo->eat_times < 0)
			return (1);
	}
	if (p->num_of_philos <= 0 || p->num_of_philos > 200)
		return (1);
	if (p->time_to_die < 60 || p->time_to_eat < 60 || p->time_to_sleep < 60)
		return (1);
	pthread_mutex_init(&p->lock, NULL);
	return (0);	
}

int	init_philo(t_philo *philo)
{
	
}

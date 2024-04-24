/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:07:58 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 14:01:14 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo *p, int ac, char **av)
{
	p->num_of_philos = ft_atoi(av[1]);
	p->time_to_die = ft_atoi(av[2]);
	p->time_to_eat = ft_atoi(av[3]);
	p->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		p->eat_times = 0;
	else
	{
		p->eat_times = ft_atoi(av[5]);
		if (p->eat_times <= 0)
			return (1);
	}
	if (p->num_of_philos <= 0 || p->num_of_philos > 200)
		return (1);
	if (p->time_to_die < 60 || p->time_to_eat < 60 || p->time_to_sleep < 60)
		return (1);
	return (0);	
}

int	main(int ac, char **av)
{
    t_philo	p;

	if (ac < 5)
	{
		printf("Error\n");
		return (1);
	}
	if (init_philo(&p, ac, av) == 1)
	{
		printf("Error\n");
		return (1);
	}
}

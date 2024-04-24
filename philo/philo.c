/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:07:58 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 12:33:18 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_philo(t_philo *p, char **av)
{
	p->num_of_philos = ft_atoi(av[1]);
	p->time_to_die = ft_atoi(av[2]);
	p->time_to_eat = ft_atoi(av[3]);
	p->time_to_sleep = ft_atoi(av[4]);
	p->num_of_times_each_philos_must_eat = ft_atoi(av[5]);
}
int main(int ac, char **av)
{
    t_philo	p;

	if (ac < 5)
	{
		printf("Error\n");
		return 1;
	}
	init_philo(&p, av);
	if (p.num_of_philos <= 0 || p.num_of_philos > 200)
	{
		printf("Error\n");
		return 1;
	}
	if (p.time_to_die < 60 || p.time_to_eat < 60 || p.time_to_sleep < 60)
	{
		printf("Error\n");
		return 1;
	}
	
	
}
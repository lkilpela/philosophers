/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:22:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 22:27:58 by lkilpela         ###   ########.fr       */
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
		p->eat_times = 0;
	else
	{
		p->eat_times = ft_atoi(av[5]);
		if (p->eat_times < 0)
			return (1);
	}
	if (p->num_of_philos <= 0 || p->num_of_philos > 200)
		return (1);
	if (p->time_to_die < 60 || p->time_to_eat < 60 || p->time_to_sleep < 60)
		return (1);
	p->philo = malloc(p->num_of_philos * sizeof(t_philo));
	if (!p->philo)
		return (1);
	return (0);
}

int	init_mutex_forks(t_program *p)
{
	int	i;

	i = 0;
	p->forks = malloc(p->num_of_philos * sizeof(pthread_mutex_t));
	if (!p->forks)
		return (1);
	while (i < p->num_of_philos)
	{
		if (pthread_mutex_init(&p->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_philo(t_program *p)
{
	int	i;

	i = 0;
	while (i < p->num_of_philos)
	{
		p->philo[i].id = i + 1;
		p->philo[i].times_eaten = 0;
		p->philo[i].last_meal = 0;
		p->philo[i].eating = 0;
		p->philo[i].left_fork = &p->forks[i];
		p->philo[i].right_fork = &p->forks[(i + 1) % p->num_of_philos];
		if (pthread_create(&p->philo[i].thread, NULL,
				start_routine, &p->philo[i]))
			return (1);
	}
}
/*
The pthread_create function in C is used to create a new thread.
It has the following parameters:

pthread_t *thread: A pointer to a pthread_t variable that the function will fill
					with the ID of the newly created thread.

const pthread_attr_t *attr: A pointer to a pthread_attr_t structure 
							that specifies thread attributes, 
							or NULL for the default attributes.

void *(*start_routine) (void *): A pointer to the function that the 
								new thread will start executing. 
								This function should take a single void * arg
								and return a void *.

void *arg: A pointer to the argument that will be passed to 
			the start_routine function.
*/
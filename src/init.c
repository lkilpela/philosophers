/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:22:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/29 14:53:59 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			return (printf("Invalid number_of_time_each_philo must eat.\n"), 1);
	}
	if (p->num_of_philos <= 0 || p->num_of_philos > 200)
		return (printf("Invalid number_of_philosophers.\n"), 1);
	if (p->time_to_die < 60 || p->time_to_eat < 60 || p->time_to_sleep < 60)
		return (printf("Invalid time value.\n"), 1);
	p->philo = malloc(p->num_of_philos * sizeof(t_philo));
	if (!p->philo)
		return (1);
	if (init_mutex_forks(p))
		return (1);
	if (pthread_mutex_init(&p->lock, NULL))
		return (1);
	return (0);
}

int init_one_philo(t_philo *philo, int i, t_program *p)
{
	philo->id = i + 1;
	philo->start_time = get_current_time();
	philo->times_eaten = 0;
	philo->died = 0;
	philo->last_ate = 0;
	philo->left_fork = &p->forks[i];
	if(i == 0) 
		philo->right_fork = &p->forks[p->num_of_philos - 1];
	else 
		philo->right_fork = &p->forks[(i - 1)];
	philo->program = p;
	if (pthread_create(&philo->thread, NULL, start_routine, philo) != 0)
		return (1);
	//philo->state = -1;
	//philo->left_philo = &p->philo[(i + philo->program->num_of_philos)
	//	% philo->program->num_of_philos];
	//philo->right_philo = &p->philo[(philo->id + 1) 
	//	% philo->program->num_of_philos];
	return (0);
}

int	init_philos(t_program *p)
{
	int	i;
	
	i = 0;
	while (i < p->num_of_philos)
	{
		if (init_one_philo(&p->philo[i], i, p))
			return (1);
		i++;
	}
	return (0);
}

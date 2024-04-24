/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:07:58 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 12:12:24 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_philo(t_philo *p, char **av)
{
	p->number_of_philosopher = ft_atoi(av[1]);
	p->time_to_die = 0;
	p->time_to_eat = 0;
	p->time_to_sleep = 0;
	p->number_of_times_each_philosopher_must_eat = 0;
}
int main(int ac, char **av)
{
    t_philo	p;

	
}
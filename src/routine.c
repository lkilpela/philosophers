/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:48:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/25 14:10:57 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_program *p)
{
	
}

void	sleeping(t_program *p)
{
	
}

void	eating(t_program *p)
{
    p->philo->last_meal = p->philo->start_time + p->time_to_eat;
}
// dies if does not eat within a certain amount of time
void	died(t_program *p)
{
	long long	starved;

	starved = get_current_time() - p->philo->last_meal;
	if (starved > p->time_to_die)
	{
		p->philo->died = 1;
		print_time_stamp(p->philo, "died\n");
	}
}

// void *(*start_routine) (void *)
// A pointer to the function that the new thread will start executing. 
//This function should take a single void * argument and return a void *.

void *start_routine(void *arg)
{
    t_program *p;

	p = (t_program *)arg;
	while(1)
	{
		thinking(p);
		eating(p);
		sleeping(p);
	}
	return (NULL);
}
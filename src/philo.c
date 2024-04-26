/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:07:58 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/26 09:04:02 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_philos(t_program *p)
{
	int	i;

	i = 0;
	while (i < p->num_of_philos)
	{
		pthread_join(p->philo[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_program	p;

	if (ac < 5)
		return (printf("Wrong argument count\n"), 1);
	if (init_program(&p, ac, av) == 1)
		return (1);
	if (init_philos(&p) == 1)
		return (1);
	wait_for_philos(&p);
	free_all(&p);
}

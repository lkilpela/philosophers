/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:07:58 by lkilpela          #+#    #+#             */
/*   Updated: 2024/06/14 11:09:46 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_philos(t_program *p)
{
	int	i;

	i = 0;
	while (i < p->num_of_philos)
	{
		if (pthread_join(p->philos[i].thread, NULL) != 0)
			free_all(p);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_program	p;

	if (argc < 5 || argc > 6)
		return (printf("Wrong argument count\n"), 1);
	if (init_program(&p, argc, argv) == 1)
		return (1);
	if (p.num_of_philos == 1)
		printf("%lld %d %s\n", p.time_to_die, 1, RED "died" NC);
	else
	{
		if (init_philos(&p) == 1)
			return (1);
		monitor_philos(&p);
		wait_for_philos(&p);
	}
	free_all(&p);
}

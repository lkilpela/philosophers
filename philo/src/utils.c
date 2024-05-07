/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:52:08 by lkilpela          #+#    #+#             */
/*   Updated: 2024/05/07 13:39:27 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_program *p)
{
	int	i;

	i = 0;
	while (i < p->num_of_philos)
	{
		pthread_mutex_destroy(&p->forks[i]);
		i++;
	}
	free(p->forks);
	pthread_mutex_destroy(&p->lock);
	pthread_mutex_destroy(&p->print_lock);
	free(p->philos);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;
	int					digit;

	result = 0;
	sign = 1;
	while ((*str == '\t' && *str == '\r') || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!((unsigned char)*str >= '0' && (unsigned char)*str <= '9'))
			return (-1);
		digit = *str - '0';
		result = (result * 10) + (digit * sign);
		str++;
	}
	return (result);
}

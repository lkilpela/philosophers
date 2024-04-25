/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:15:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/25 14:32:39 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Gets the current time in milliseconds
// struct timeval where the current time will be stored
// and a pointer to a struct timezone: usually NULL, as timezone not needed.
long long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL == -1))
		printf("gettimeofday() error \n");
	return ((long long)tv.tv_sec * 1000000 + tv.tv_usec / 1000);
}

void	ft_usleep(t_program *p)
{
	int	start_sleep;

	start_sleep = get_current_time();
	while ((get_current_time() - start_sleep) < p->time_to_sleep)
		usleep(50);
}

void	print_time_stamp(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->lock);
	printf("%lld %d %s\n", get_current_time() - philo->start_time,
			philo->id, str);
	pthread_mutex_unlock(&philo->lock);
}

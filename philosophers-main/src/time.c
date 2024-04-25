/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:15:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/25 15:58:15 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Gets the current time in milliseconds
// struct timeval where the current time will be stored
// and a pointer to a struct timezone: usually NULL, as timezone not needed.
long long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long time)
{
	long long	start_sleep;

	start_sleep = get_current_time();
	while ((get_current_time() - start_sleep) < time)
		usleep(50);
}

void	print_time_stamp(t_philo *p, char *str)
{
	long long time;

	pthread_mutex_lock(&p->program->lock);
	time = get_current_time() - p->start_time;
	printf("%lld %d %s\n", time, p->id, str);
	pthread_mutex_unlock(&p->program->lock);
}
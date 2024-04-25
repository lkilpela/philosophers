/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:15:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/25 11:30:03 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Gets the current time in milliseconds
int get_time(void)
{
	struct timeval	tv;

    if (gettimeofday(&tv, NULL == 1))
		return (1);
	return (tv.tv_sec * 1000000 + tv.tv_usec / 1000);    
}

void	usleep()
{
	
}

void	time_stamp(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->lock);
	printf("%d %d %s\n", get_time() - philo->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->lock);
}
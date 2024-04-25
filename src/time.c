/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:15:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/25 13:58:45 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Gets the current time in milliseconds
// struct timeval where the current time will be stored
// and a pointer to a struct timezone: usually NULL, as timezone not needed.
long long get_current_time(void)
{
	struct timeval	tv;

    if (gettimeofday(&tv, NULL == -1))
		printf("gettimeofday() error \n");
	return ((long long)tv.tv_sec * 1000000 + tv.tv_usec / 1000);
}

void	ft_usleep(t_philo *philo, int milliseconds)
{
	int	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(50);
}

void	print_time_stamp(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->lock);
	printf("%d %d %s\n", get_time() - philo->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->lock);
}

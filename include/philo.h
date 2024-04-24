/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:55:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 12:16:03 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
# include <pthread.h>
# include <stdio.h>     // printf
//# include <limits.h>
# include <unistd.h>    // write, usleep
# include <stdlib.h>    // malloc, free
# include <sys/time.h>  // gettimeofday, 
# include <string.h>    // memset

typedef struct  s_philo
{
	int num_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_times_each_philos_must_eat;
}               t_philo;


#endif
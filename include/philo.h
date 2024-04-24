/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:55:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 12:07:30 by lkilpela         ###   ########.fr       */
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
    int number_of_philosopher;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;   
}               t_philo;


#endif
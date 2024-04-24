/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:55:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 15:22:38 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
# include <pthread.h>
# include <stdio.h>     // printf
# include <unistd.h>    // write, usleep
# include <stdlib.h>    // malloc, free
# include <sys/time.h>  // gettimeofday, 
# include <string.h>    // memset

typedef struct  s_philo
{
	int				id;				// Each philo's unique identifier
	int 			eat_times;		// Number of times each philo must eat
	int				start_time;
	int				times_eaten;	// A count of eaten times
	int				dead;
	pthread_mutex_t	*left_fork;		// Pointer to mutex: left fork philo uses
	pthread_mutex_t	*rightt_fork;	// Pointer to mutex: right fork philo uses
	pthread_t		thread;			// Philo's thread
}               t_philo;

typedef struct	s_program
{
	int 			num_of_philos;
	int 			time_to_die;
	int 			time_to_eat;
	int 			time_to_sleep;
	pthread_mutex_t	lock;
	t_philo			*philo;
}				t_program;
//init
int	init_program(t_program *p, int ac, char **av);

//utils

int	ft_atoi(const char *str);

#endif
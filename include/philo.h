/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:55:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/25 15:12:59 by lkilpela         ###   ########.fr       */
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

# define FAILURE	1
# define SUCCESS	0
# define TRUE		0
# define FALSE		1

typedef struct  s_philo
{
	int				id;				// Each philo's unique identifier
	long long		start_time;
	int				times_eaten;	// A count of eaten times
	int				died;			// flag
	long long		last_eaten;
	//int				eating;			// flag	
	pthread_mutex_t	*left_fork;		// Pointer to mutex: left fork philo uses
	pthread_mutex_t	*right_fork;	// Pointer to mutex: right fork philo uses
	pthread_mutex_t	lock;
	pthread_t		thread;			// Philo's thread
}               t_philo;

typedef struct	s_program
{
	int 			num_of_philos;
	long long 		time_to_die;
	long long 		time_to_eat;
	long long 		time_to_sleep;
	int 			eat_times;		// Number of times each philo must eat
	pthread_mutex_t	*forks;
	t_philo			*philo;
}				t_program;
//init
int		init_program(t_program *p, int ac, char **av);
int		init_philos(t_program *p);
int 	init_mutex_forks(t_program *p);

//
void 	*start_routine(void *arg);
void	died(t_program *p);

// time
int 	get_current_time(void);
void	print_time_stamp(t_philo *philo, char *str);
void	ft_usleep(t_program *p, long long time);
//utils
void	free_all(t_program *p);
int		ft_atoi(const char *str);

#endif
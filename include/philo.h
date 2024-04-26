/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:55:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/26 15:43:58 by lkilpela         ###   ########.fr       */
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

# define NC	"\e[0m"
# define YELLOW	"\e[0;33m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define GREY "\e[0;30m"
# define RED "\e[0;31m"
# define CYAN "\e[0;36m"

typedef struct  s_philo
{
	int					id;				// Each philo's unique identifier
	long long			start_time;
	int					times_eaten;	// A count of eaten times
	int					died;			// flag
	long long			last_eaten;		// flag	
	pthread_mutex_t		*left_fork;		// Pointer to mutex: left fork philo uses
	pthread_mutex_t		*right_fork;	// Pointer to mutex: right fork philo uses
	pthread_t			thread;	
	struct s_program	*program;		// Philo's thread
}               t_philo;

typedef struct	s_program
{
	int 				num_of_philos;
	long long 			time_to_die;
	long long 			time_to_eat;
	long long 			time_to_sleep;
	int 				eat_times;		// Number of times each philo must eat
	pthread_mutex_t		*forks;
	t_philo				*philo;
	pthread_mutex_t		lock;
}				t_program;
//init
int			init_program(t_program *p, int ac, char **av);
int			init_philos(t_program *p);
int 		init_mutex_forks(t_program *p);

//
void 		*start_routine(void *arg);
int			check_if_died(t_philo *philo);

// time
long long 	get_current_time(void);
void		print_time_stamp(t_philo *philo, char *str);
void		ft_usleep(long long time);
//utils
void		free_all(t_program *p);
int			ft_atoi(const char *str);

#endif
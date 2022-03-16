/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:32:25 by dpiza             #+#    #+#             */
/*   Updated: 2022/03/16 18:22:06 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
** Used to identify the message to be printed to the terminal
*/
# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3
# define DIE	4
# define FULL	5

/**
* Stores the arguments provided with the program call
* and the environment variables
* @param fork An array containing all the mutexes for the forks
* @param n_philos Provided param number_of_philosophers
* @param time_to_die Provided param time_to_die
* @param time_to_eat Provided param time_to_eat
* @param time_to_sleep Provided param time_to_sleep
* @param n_must_eat Provided param number_of_times_each_philosopher_must_eat
* @param start_time The time the program started (in milliseconds)
* @param stop Variable used to stop the simulation
*/
typedef struct s_environment
{
	pthread_mutex_t	*fork;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_must_eat;
	long int		start_time;
	int				stop;
}	t_env;

/**
* Stores the data of each philosopher
* @param env A pointer to the t_env struct
* @param thread Identifies the philosopher's thread
* @param id An int identifying the phgilosopher
* @param last_meal Timestamp (in milliseconds) of the last finished meal
* @param n_meals Number of completed meals
*/
typedef struct s_philosopher
{
	t_env			*env;
	pthread_t		thread;
	int				id;
	long int		last_meal;
	int				n_meals;
}	t_philo;

/*
** lifecicle.c
*/
void		philo_think(t_philo *philo, int time);
void		philo_sleep(t_philo *philo);
int			philo_eat(t_philo *philo);
void		*lifecicle(void *arg);

/*
** threads.c
*/
void		init_mutex(t_env *env);
void		join_threads(t_philo **philo, t_env *env);

/*
** utils.c
*/
int			ft_atoi(const char *nptr);
long int	get_time(long int start);

/*
** print.c
*/
void		print(long int start_time, int id, int action);
void		print_exit(void);

#endif

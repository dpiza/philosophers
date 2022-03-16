/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:32:25 by dpiza             #+#    #+#             */
/*   Updated: 2022/03/15 22:48:56 by dpiza            ###   ########.fr       */
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

# define USAGE	1
# define ARGS	2

# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3
# define DIE	4
# define FULL	5

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

typedef struct s_philosopher
{
	t_env			*env;
	pthread_t		thread;
	long int		last_meal;
	int				n_meals;
	int				id;
}	t_philo;

/*
** philo_utils.c
*/
int			ft_atoi(const char *nptr);
void		print_exit(int err);
long int	get_time(long int start);
void		philo_sleep(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo);
void		print(long int start_time, int id, int action);
void		philo_daemon(t_philo **philo, t_env *env);
void		*philo_thread(void *arg);

void		_print_struct(t_env *env, int argc);

#endif

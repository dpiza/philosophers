/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:31:31 by dpiza             #+#    #+#             */
/*   Updated: 2022/03/15 22:56:30 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	check_args(int argc)
{
	if (argc < 5)
		print_exit(USAGE);
	else if (argc > 6)
		print_exit(ARGS);
}

static void	init_struct(t_env *env, int argc, char **argv)
{
	env->n_philos = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		env->n_must_eat = ft_atoi(argv[5]);
	env->start_time = get_time(0);
	if (!env->n_philos || !env->time_to_die || !env->time_to_eat
		|| !env->time_to_sleep || !env->n_must_eat)
		print_exit(ARGS);
	_print_struct(env, argc);
	env->stop = 0;
}

static void	create_philos(t_philo **philo, t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->n_philos)
	{
		philo[0][i].env = env;
		philo[0][i].id = i;
		philo[0][i].n_meals = 0;
		philo[0][i].last_meal = env->start_time;
		pthread_create(&philo[0][i].thread, NULL, &philo_thread, &philo[0][i]);
	}
}

static void	join_threads(t_philo **philo, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->n_philos)
	{
		pthread_join(philo[0][i].thread, NULL);
		// printf("Thread %i joined\n", i);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_env		env;
	t_philo		*philo;

	check_args(argc);
	init_struct(&env, argc, argv);
	philo = malloc(env.n_philos * sizeof(t_philo));
	env.fork = malloc(env.n_philos * sizeof(pthread_mutex_t));
	create_philos(&philo, &env);
	philo_daemon(&philo, &env);
	join_threads(&philo, &env);
	free(philo);
	free(env.fork);
	return (0);
}

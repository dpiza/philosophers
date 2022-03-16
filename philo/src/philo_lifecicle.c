/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecicle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:53 by dpiza             #+#    #+#             */
/*   Updated: 2022/03/15 22:51:22 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_think(t_philo *philo)
{
	print(philo->env->start_time, philo->id, THINK);
}

void	philo_sleep(t_philo *philo)
{
	print(philo->env->start_time, philo->id, SLEEP);
	usleep(philo->env->time_to_sleep * 1000);
}

void	philo_eat(t_philo *philo)
{
	if (philo->id == philo->env->n_philos - 1)
		pthread_mutex_lock(&philo->env->fork[0]);
	else
		pthread_mutex_lock(&philo->env->fork[philo->id + 1]);
	print(philo->env->start_time, philo->id, FORK);
	pthread_mutex_lock(&philo->env->fork[philo->id]);
	print(philo->env->start_time, philo->id, FORK);
	print(philo->env->start_time, philo->id, EAT);
	philo->last_meal = get_time(0);
	philo->n_meals++;
	usleep(philo->env->time_to_eat * 1000);
	if (philo->id == philo->env->n_philos - 1)
		pthread_mutex_unlock(&philo->env->fork[0]);
	else
		pthread_mutex_unlock(&philo->env->fork[philo->id + 1]);
	pthread_mutex_unlock(&philo->env->fork[philo->id]);
}

void	philo_daemon(t_philo **philo, t_env *env)
{
	int			i;
	int			max_meals;
	long int	last_m;

	i = 0;
	max_meals = 0;
	while (1)
	{
		last_m = get_time(philo[0][i % env->n_philos].last_meal);
		if (last_m > env->time_to_die)
		{
			print(env->start_time, philo[0][i % env->n_philos].id, DIE);
			philo[0][i % env->n_philos].env->stop = 1;
			return ;
		}
		if (philo[0][i % env->n_philos].n_meals == env->n_must_eat)
			max_meals++;
		if (max_meals == env->n_philos)
		{
			print(env->start_time, 665, FULL);
			philo[0][i % env->n_philos].env->stop = 1;
			return ;
		}
		i++;
	}
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = arg;
	printf("%5.3ld %5d joined the party\n",
		get_time(philo->env->start_time), philo->id + 1);
	while (!philo->env->stop)
	{
		if (philo->id % 2)
		{
			philo_think(philo);
			usleep(philo->env->time_to_eat);
		}
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

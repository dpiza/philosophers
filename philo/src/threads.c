/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:14:55 by dpiza             #+#    #+#             */
/*   Updated: 2022/03/16 17:16:21 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_mutex(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->n_philos)
	{
		pthread_mutex_init(&env->fork[i], NULL);
		i++;
	}
}

void	join_threads(t_philo **philo, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->n_philos)
	{
		pthread_join(philo[0][i].thread, NULL);
		i++;
	}
}

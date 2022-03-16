/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:50:13 by dpiza             #+#    #+#             */
/*   Updated: 2022/03/16 17:38:42 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(long int start_time, int id, int action)
{
	static char	*message[6] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died",
		"all philosophers exploded"
	};

	printf("%5.3ld %5d %s\n", get_time(start_time), id + 1, message[action]);
}

void	_print_struct(t_env *env, int argc)
{
	printf("-----t_env-----\n");
	printf("n_philo:\t%d\n", env->n_philos);
	printf("time_to_die:\t%d\n", env->time_to_die);
	printf("time_to_eat:\t%d\n", env->time_to_eat);
	printf("time_to_sleep:\t%d\n", env->time_to_sleep);
	if (argc == 6)
		printf("each_must_eat:\t%d\n", env->n_must_eat);
	printf("-----t_env-----\n\n");
}

void	print_exit(void)
{
	printf("philo: Invalid Argument\n\n");
	printf("Usage:\n./philo [n_philo] [time_to_die]");
	printf(" [time_to_eat] [time_to_sleep]");
	printf(" [number_of_times_each_philosopher_must_eat]\n\n");
	exit (1);
}

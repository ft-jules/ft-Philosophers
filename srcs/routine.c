/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:24:48 by jules             #+#    #+#             */
/*   Updated: 2024/10/21 11:39:24 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg) // fonction qui print les infos du philo
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf(RED "philo[%d]:\n" RST, philo->id);
    printf("dead[%d]: %d\n", philo->id, philo->dead);
    printf("status[%d]: %d\n", philo->id, philo->status);
    printf("ttdie[%d]: %zu\n", philo->id, philo->ttdie);
    printf("tteat[%d]: %zu\n", philo->id, philo->tteat);
    printf("ttsleep[%d]: %zu\n", philo->id, philo->ttsleep);
    printf("r_fork[%d]: %p\n", philo->id, philo->r_fork);
    printf("l_fork[%d]: %p\n", philo->id, philo->l_fork);
    printf("lock[%d]: %p\n", philo->id, philo->lock);
    printf("warden_lock[%d]: %p\n", philo->id, philo->warden_lock);
    printf("print_lock[%d]: %p\n\n", philo->id, philo->print_lock);
    return (NULL);
}

bool	launch_routine(t_data *data)
{
	int i;

	i = 0;
	while (i < (int)data->philo_nb)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine,
				&data->philo[i]))
			return (printf(RED "Thread creation error\n" RST), true);
		i++;
	}
	i = 0;
	while (i < (int)data->philo_nb)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (printf(RED "Thread join error\n" RST), true);
		i++;
	}
	return (false);
}
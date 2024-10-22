/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:24:48 by jules             #+#    #+#             */
/*   Updated: 2024/10/22 11:40:39 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg) // fonction qui print les infos du philo
{
	t_philo *philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->lock);
	printf(RED "philo[%d]:\n" RST, philo->id);
	printf("dead[%d]: %d\n", philo->id, philo->dead);
	printf("status[%d]: %d\n", philo->id, philo->status);
	printf("ttdie[%d]: %zu\n", philo->id, philo->ttdie);
	printf("tteat[%d]: %zu\n", philo->id, philo->tteat);
	printf("ttsleep[%d]: %zu\n", philo->id, philo->ttsleep);
	printf("r_fork[%d]: %p\n", philo->id, philo->r_fork);
	printf("l_fork[%d]: %p\n", philo->id, philo->l_fork);
	printf("lock[%d]: %p\n", philo->id, philo->lock);
	printf("monitor_lock[%d]: %p\n", philo->id, philo->monitor_lock);
	printf("print_lock[%d]: %p\n\n", philo->id, philo->print_lock);
	pthread_mutex_unlock(philo->lock);
	return (NULL);
}

bool	th_join(t_data *data)
{
	int	i;

	i = -1;
	if (pthread_join(data->monitor, NULL))
		return (printf("monitor join failure"), true);
	while (++i < (int)data->philo_nb)
		if (pthread_join(data->philo[i].thread, NULL))
			return (printf("Philo join failure"), true);
	return (false);
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
	if (pthread_create(&data->monitor, NULL, &monitoring, (void *)data))
		return (printf(RED "Thread creation error\n" RST), true);
	
	if (th_join(data))
		return (true);
	return (false);
}
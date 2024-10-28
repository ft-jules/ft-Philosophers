/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpointil <jpointil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:24:48 by jules             #+#    #+#             */
/*   Updated: 2024/10/28 11:04:07 by jpointil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	sync_th(t_philo *philo)
{
	while (true)
	{
		pthread_mutex_lock(philo->lock);
		if (philo->data->created == (int)philo->philo_nb + 1)
		{
			philo->last_meal = get_time();
			pthread_mutex_unlock(philo->lock);
			break ;
		}
		pthread_mutex_unlock(philo->lock);
		usleep(100);
	}
	return ;
}

int	check_routine(t_philo *philo)
{
	if (philo->meals == 0)
		return (1);
	if (philo->dead)
	{
		pthread_mutex_lock(philo->lock);
		printf("philo[%d], died\n", philo->id);
		pthread_mutex_unlock(philo->lock);
		return (2);
	}
	return (0);
}

void	eat_ac(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	philo->status = EAT;
	philo->meals--;
	philo->last_meal = get_time();
	pthread_mutex_lock(philo->lock);
	printf(GREEN "philo[%d] is eating\n" RST, philo->id);
	pthread_mutex_unlock(philo->lock);
	usleep(philo->tteat * 1000);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->lock);
	philo->data->created++;
	pthread_mutex_unlock(philo->lock);
	sync_th(philo);
	while (!check_routine(philo))
	{
		pthread_mutex_lock(philo->lock);
		printf(CYAN "philo[%d] is thinking\n" RST, philo->id);
		pthread_mutex_unlock(philo->lock);
		philo->status = SLEEP;
		pthread_mutex_lock(philo->lock);
		printf(PURPLE "philo[%d] is sleeping\n" RST, philo->id);
		pthread_mutex_unlock(philo->lock);
		usleep(philo->ttsleep * 1000);
		eat_ac(philo);
	}
	return (NULL);
}

// void	*routine(void *arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;
// 	pthread_mutex_lock(philo->lock);
// 	printf(RED "philo[%d]:\n" RST, philo->id);
// 	printf("dead[%d]: %d\n", philo->id, philo->dead);
// 	printf("status[%d]: %d\n", philo->id, philo->status);
// 	printf("ttdie[%d]: %zu\n", philo->id, philo->ttdie);
// 	printf("tteat[%d]: %zu\n", philo->id, philo->tteat);
// 	printf("ttsleep[%d]: %zu\n", philo->id, philo->ttsleep);
// 	printf("r_fork[%d]: %p\n", philo->id, philo->r_fork);
// 	printf("l_fork[%d]: %p\n", philo->id, philo->l_fork);
// 	printf("lock[%d]: %p\n", philo->id, philo->lock);
// 	printf("monitor_lock[%d]: %p\n", philo->id, philo->monitor_lock);
// 	printf("print_lock[%d]: %p\n\n", philo->id, philo->print_lock);
// 	pthread_mutex_unlock(philo->lock);
// 	return (NULL);
// }

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
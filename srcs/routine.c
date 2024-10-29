/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:24:48 by jules             #+#    #+#             */
/*   Updated: 2024/10/29 19:37:23 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	sync_th(t_philo *philo)
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

static void	eat_ac(t_philo *philo)
{
	bool	l;

	l = false;
	if (philo->id != (int)philo->philo_nb)
	{
		pthread_mutex_lock(philo->l_fork);
		l = true;
	}
	else
		pthread_mutex_lock(philo->r_fork);
	t_print("has taken a fork", philo);
	pthread_mutex_lock(philo->lock);
	philo->eating = true;
	philo->meals--;
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->lock);
	t_print("is eating" RST, philo);
	usleep(philo->tteat * 1000);
	pthread_mutex_lock(philo->lock);
	philo->eating = false;
	pthread_mutex_unlock(philo->lock);
	if (l)
		pthread_mutex_unlock(philo->l_fork);
	else
		pthread_mutex_unlock(philo->r_fork);
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_nb == 1)
	{
		t_print(WHITE "is taking a fork" RST, philo);
		usleep(philo->ttdie * 1000);
		return (false);
	}
	pthread_mutex_lock(philo->lock);
	philo->data->created++;
	pthread_mutex_unlock(philo->lock);
	sync_th(philo);
	if ((philo->id % 2) == 0)
		usleep(1000);
	while (!check_routine(philo->data))
	{
		eat_ac(philo);
		t_print(PURPLE "is sleeping" RST, philo);
		usleep(philo->ttsleep * 1000);
		t_print(BLUE "is thinking" RST, philo);
		usleep(800);
	}
	return (arg);
}

static bool	th_join(t_data *data)
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

bool	wakeup_philos(t_data *data)
{
	int	i;

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

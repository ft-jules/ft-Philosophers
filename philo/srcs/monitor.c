/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpointil <jpointil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:54:36 by jules             #+#    #+#             */
/*   Updated: 2024/10/31 14:21:15 by jpointil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	check_routine(t_data *data)
{
	pthread_mutex_lock(&data->monitor_lock);
	if (data->death)
		return (pthread_mutex_unlock(&data->monitor_lock), true);
	return (pthread_mutex_unlock(&data->monitor_lock), false);
}

static bool	check_death(t_data *data)
{
	int	i;

	i = -1;
	while (++i < (int)data->philo_nb)
	{
		pthread_mutex_lock(&data->lock);
		if (get_time() - data->philo[i].last_meal >= data->ttdie
			&& !data->philo[i].eating)
		{
			t_print(RED "died" RST, &data->philo[i]);
			data->philo[i].dead = true;
			pthread_mutex_lock(&data->monitor_lock);
			data->death = true;
			pthread_mutex_unlock(&data->monitor_lock);
			pthread_mutex_unlock(&data->lock);
			return (data->death);
		}
		pthread_mutex_unlock(&data->lock);
	}
	return (data->death);
}

bool	check_meals(t_data *data)
{
	int	finished;
	int	id;

	id = -1;
	finished = 0;
	if ((int)data->meals >= 0)
	{
		while (++id < (int)data->philo_nb)
		{
			pthread_mutex_lock(&data->lock);
			if ((int)data->philo[id].meals <= 0)
				finished++;
			pthread_mutex_unlock(&data->lock);
		}
		if (finished == (int)data->philo_nb)
		{
			pthread_mutex_lock(&data->monitor_lock);
			data->death = true;
			pthread_mutex_unlock(&data->monitor_lock);
		}
	}
	return (data->death);
}

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->lock);
	data->created++;
	pthread_mutex_unlock(&data->lock);
	while (true)
	{
		usleep(850);
		if (check_death(data))
			break ;
		if (check_meals(data))
		{
			pthread_mutex_lock(&data->print_lock);
			printf(GREEN "Philo are all stuffed to the gills\n" RST);
			pthread_mutex_unlock(&data->print_lock);
			break ;
		}
	}
	return (arg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpointil <jpointil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:54:36 by jules             #+#    #+#             */
/*   Updated: 2024/10/28 11:29:52 by jpointil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*monitoring(void *arg)
{
	t_data *data;

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
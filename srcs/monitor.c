/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:54:36 by jules             #+#    #+#             */
/*   Updated: 2024/10/24 16:31:37 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->lock);
	data->created++;
	pthread_mutex_unlock(&data->lock);
	pthread_mutex_lock(&data->print_lock);
    printf(GREEN "monitoring\n" RST);
    pthread_mutex_unlock(&data->print_lock);
	return (arg);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:41:03 by jules             #+#    #+#             */
/*   Updated: 2024/10/21 13:49:27 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= (int)data->philo_nb)
	{
        data->philo[i].status = INIT;
		data->philo[i].id = i + 1;
		data->philo[i].dead = FALSE;
		data->philo[i].ttdie = data->ttdie;
		data->philo[i].tteat = data->tteat;
		data->philo[i].ttsleep = data->ttsleep;
        data->philo[i].r_fork = &data->forks[i];
		if (i)
			data->philo[i].l_fork = &data->forks[i - 1];
		else
			data->philo[i].l_fork = &data->forks[data->philo_nb - 1];
        data->philo[i].lock = &data->lock;
		data->philo[i].warden_lock = &data->warden_lock;
		data->philo[i].print_lock = &data->print_lock;
	}
	printf(GREEN "init_philo\n" RST);
}

bool	init_data(t_data *data, int i)
{
	data->philo = malloc(sizeof(t_philo) * data->philo_nb);
	if (!data->philo)
		return (printf(RED A_ERR RST), true);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	if (!data->forks)
		return (free(data->philo), printf(RED A_ERR RST), true);
	while (i > 0)
	{
		i--;
		pthread_mutex_init(&data->forks[i], NULL);
	}
	data->death = FALSE;
	init_philo(data);
	return (printf(GREEN "init_data\n\n" RST), false);
}

bool	init(t_data *data, int ac, char **av)
{
	data->philo_nb = ft_atoi(av[1]);
	data->ttdie = ft_atoi(av[2]);
	data->tteat = ft_atoi(av[3]);
	data->ttsleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals = ft_atoi(av[5]);
	else
		data->meals = -1; // boucler a l'inifini
	printf(GREEN "init_args\n" RST);
	if (init_data(data, data->philo_nb))
		return (printf(RED A_ERR RST), true);
	return (false);
}

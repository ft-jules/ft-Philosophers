/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpointil <jpointil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:01:51 by jules             #+#    #+#             */
/*   Updated: 2024/10/31 14:24:59 by jpointil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	t_print(char *str, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->print_lock);
	time = get_time() - philo->creation_time;
	if (!check_routine(philo->data))
		printf("%zu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->print_lock);
}

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->monitor_lock);
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->print_lock);
	while (++i < (int)data->philo_nb)
		pthread_mutex_destroy(&data->forks[i]);
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
}

// void	free_data(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < (int)data->philo_nb)
// 	{
// 		pthread_mutex_destroy(&data->forks[i]);
// 		free_philo(&data->philo[i]);
// 		free(&data->forks[i]);
// 		i++;
// 	}
// 	free(data->forks);
// }

int	is_pos_int(char *str, int flag)
{
	long	nb;
	long	i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (printf(RED "Only positive int required\n" RST), 1);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (flag == 5 && nb == 0)
		return (printf(GREEN "Philo are all stuffed to the gills\n" RST), 1);
	if (nb <= 0 || nb > INT_MAX)
		return (printf(RED "Only positive int required\n" RST), 1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	size_t	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

size_t	get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		printf("Get time error");
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

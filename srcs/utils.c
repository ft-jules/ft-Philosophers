/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:01:51 by jules             #+#    #+#             */
/*   Updated: 2024/10/21 11:21:19 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_data(t_data *data)
{
	int i;

	i = 0;
	printf(PURPLE "philo_nb: %zu\nttdie: %zu\ntteat: %zu\nttsleep: %zu\nmeals: %zu\n\n" RST, data->philo_nb, data->ttdie, data->tteat, data->ttsleep, data->meals);
	printf(BROWN "forks:\n\n" RST);
	while (i < (int)data->philo_nb)
	{
		printf(CYAN "fork[%d]:\n" RST, i);
		printf("lock: %p\n\n", &data->forks[i]);
		i++;
	}
	i = 1;
	printf(BROWN "philos:\n\n" RST);
	while (i <= (int)data->philo_nb)
	{
		printf(CYAN "philo[%d]:\n" RST, i);
		printf("id: %d\n", data->philo[i].id);
		printf("dead: %d\n", data->philo[i].dead);
		printf("status: %d\n", data->philo[i].status);
		printf("ttdie: %zu\n", data->philo[i].ttdie);
		printf("tteat: %zu\n", data->philo[i].tteat);
		printf("ttsleep: %zu\n", data->philo[i].ttsleep);
		printf("r_fork: %p\n", data->philo[i].r_fork);
		printf("l_fork: %p\n", data->philo[i].l_fork);
		printf("lock: %p\n", data->philo[i].lock);
		printf("warden_lock: %p\n", data->philo[i].warden_lock);
		printf("print_lock: %p\n\n", data->philo[i].print_lock);
		i++;
	}
}

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

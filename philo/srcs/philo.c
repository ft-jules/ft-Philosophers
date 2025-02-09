/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpointil <jpointil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:43:49 by jules             #+#    #+#             */
/*   Updated: 2024/10/31 11:33:03 by jpointil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static bool	check_args(char **av, int ac)
{
	int	i;

	i = 0;
	while (av[++i] && i < ac)
	{
		if (is_pos_int(av[i], i))
			return (true);
	}
	return (false);
}

int	main(int ac, char **av)
{
	t_data	data;

	if ((ac < 5 || ac > 6))
	{
		printf(RED "Error: wrong number of arguments\n" RST);
		printf(RED "Usage: ./philo [philo nb] [die time]" RST);
		printf(RED "[eat time] [sleep time] [meals nb for each]\n" RST);
		return (1);
	}
	if (check_args(av, ac))
		return (2);
	if (init(&data, ac, av))
		return (3);
	if (wakeup_philos(&data))
		return (4);
	free_data(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:43:49 by jules             #+#    #+#             */
/*   Updated: 2024/10/21 11:33:28 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	check_args(char **av, int ac)
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
		printf(RED "Usage: ./philo [philo nb] [die time] [eat time] [sleep time] [meals nb for each]\n" RST);
		return (1);
	}
	if (check_args(av, ac))
		return (2);
	if (init(&data, ac, av))
		return (3);
	if (launch_routine(&data))
		return (4);
	printf(GREEN "philo_OK\n\n" RST);
	free(data.philo);
	return (0);
}

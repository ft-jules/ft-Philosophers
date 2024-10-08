/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:43:49 by jules             #+#    #+#             */
/*   Updated: 2024/10/08 15:13:26 by jules            ###   ########.fr       */
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
	printf(PURPLE "philo_nb: %zu\nttdie: %zu\ntteat: %zu\nttsleep: %zu\nmeals: %zu\n\n" RST, data.philo_nb, data.ttdie, data.tteat, data.ttsleep, data.meals);
	printf(GREEN "philo_OK\n\n" RST);
	free(data.philo);
	return (0);
}

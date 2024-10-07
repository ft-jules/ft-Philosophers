/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:43:49 by jules             #+#    #+#             */
/*   Updated: 2024/10/07 17:41:20 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_args(char **av, int ac)
{
	int	i;

	i = 0;
	while (av[++i] && i < ac)
	{
		printf("av[%d] = %s\n", i, av[i]);
		if (is_pos_int(av[i], i))
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if ((ac < 5 || ac > 6))
	{
		printf(RED "Error: wrong number of arguments\n" RST);
		printf(RED "Usage: ./philo [philo nb] [die time] [eat time] [sleep time] [meals nb for each]\n" RST);
		return (1);
	}
	if (check_args(av, ac))
		return (2);
	printf(GREEN "philo\n" RST);	
	return (0);
}

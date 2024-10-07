/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:01:51 by jules             #+#    #+#             */
/*   Updated: 2024/10/07 17:33:43 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_pos_int(char *str, int flag)
{
	long	nb;
	long	i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (printf(RED "Only positive int required\n" RST), 1); // cas ou pas un digit
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (flag == 5 && nb == 0)
        return (printf(RED "Philo are all stuffed to the gills\n" RST), 1); // si 0 repas a manger
	if (nb <= 0 && nb > INT_MAX)
		return (printf(RED "Only positive int required\n" RST), 1); // si c'est pas un int positif
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
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

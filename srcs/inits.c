/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:41:03 by jules             #+#    #+#             */
/*   Updated: 2024/10/08 11:40:15 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
bool    init_data(t_data *data)
{
    printf("init_data -> ");
    data->philo = malloc(sizeof(t_philo) * data->philo_nb);
    if (!data->philo)
        return (printf(RED A_ERR RST), false);
    data->death = FALSE;
    return (printf(GREEN "init_data\n\n" RST), true);
}

bool init_args(t_data *data, int ac, char **av)
{
    printf("init_args -> ");
    data->philo_nb = ft_atoi(av[1]);
    data->ttdie = ft_atoi(av[2]);
    data->tteat = ft_atoi(av[3]);
    data->ttsleep = ft_atoi(av[4]);
    if (ac == 6)
        data->meals = ft_atoi(av[5]);
    else
        data->meals = -1; // boucler a l'inifini
    printf(GREEN "init_args\n" RST);
    if (!init_data(data))
        return (printf(RED A_ERR RST), false);
    return (true);
}

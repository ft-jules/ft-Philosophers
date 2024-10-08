/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:41:03 by jules             #+#    #+#             */
/*   Updated: 2024/10/08 15:57:53 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    init_philo(t_data *data)
{
    int i;

    i = -1;
    while (++i < (int)data->philo_nb)
    {
        data->philo[i].id = i;
        data->philo[i].dead = FALSE;
        data->philo[i].ttdie = data->ttdie;
        data->philo[i].tteat = data->tteat;
        data->philo[i].ttsleep = data->ttsleep;
        //pthread_mutex_init(&data->philo[i].r_fork, NULL);
        //pthread_mutex_init(&data->philo[i].l_fork, NULL);
    }
    printf(GREEN "init_philo\n" RST);
}

bool    init_data(t_data *data)
{
    data->philo = malloc(sizeof(t_philo) * data->philo_nb);
    if (!data->philo)
        return (printf(RED A_ERR RST), true);
    data->death = FALSE;
    init_philo(data);
    return (printf(GREEN "init_data\n\n" RST), false);
}

bool init(t_data *data, int ac, char **av)
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
    if (init_data(data))
        return (printf(RED A_ERR RST), true);
    return (false);
}

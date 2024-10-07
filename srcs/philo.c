/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:43:49 by jules             #+#    #+#             */
/*   Updated: 2024/10/07 10:09:09 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

int main(int argc, char **argv)
{
    (void)argc;
    if (!argv[1])
    {
        printf(RED "no args!!!\n" RESET);
        return (-1);
    }
    printf(GREEN "%s\n" RESET, argv[1]);
    return (0);
    
}

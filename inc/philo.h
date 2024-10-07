/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:27:52 by jpointil          #+#    #+#             */
/*   Updated: 2024/10/07 09:59:05 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*--------------libraries----------------*/

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

/*---------------colors--------------*/

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"

/*---------------macros--------------*/

# define TRUE 1
# define FALSE 0
# define A_ERR "Allocation error\n"

/*-------------structures-------------*/

//t_philo

/*-------------functions-------------*/

//ft_philo

#endif
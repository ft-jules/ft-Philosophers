/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:27:52 by jpointil          #+#    #+#             */
/*   Updated: 2024/10/08 15:41:03 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*--------------libraries----------------*/

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*---------------colors--------------*/

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RST "\033[0m"
# define BROWN "\033[0;33m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"

/*---------------macros--------------*/

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define A_ERR "Allocation error\n"

/*-------------structures-------------*/

typedef struct s_philo
{
	pthread_t		*thread;

	int				id;
	bool			dead;

	size_t			ttdie;
	size_t			tteat;
	size_t			ttsleep;

	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;

}					t_philo;

typedef struct s_data
{
	t_philo			*philo;

	bool			death;

	size_t		philo_nb;
	size_t			ttdie;
	size_t			tteat;
	size_t			ttsleep;
	size_t			meals;

	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;

	pthread_t		*warden;
}					t_data;

/*-------------functions-------------*/

// utils :

int					ft_atoi(const char *str);
size_t				get_time(void);
int					is_pos_int(char *str, int flag);

//main :

bool				init(t_data *data, int ac, char **av);

#endif
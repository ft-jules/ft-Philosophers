/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:27:52 by jpointil          #+#    #+#             */
/*   Updated: 2024/10/29 17:28:32 by jules            ###   ########.fr       */
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
# define YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define WHITE "\033[0;37m"

/*---------------macros--------------*/

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define A_ERR "Allocation error\n"

/*-------------structures-------------*/

typedef struct s_philo
{
	pthread_t		thread;

	struct s_data	*data;

	int				id;
	bool			dead;
	bool			eating;
	size_t			last_meal;
	size_t			creation_time;

	size_t			ttdie;
	size_t			tteat;
	size_t			ttsleep;

	size_t			philo_nb;
	size_t			meals;

	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*monitor_lock;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*lock;

}					t_philo;

typedef struct s_data
{
	t_philo			*philo;

	bool			death;

	int				created;

	size_t			philo_nb;
	size_t			ttdie;
	size_t			tteat;
	size_t			ttsleep;
	size_t			meals;

	pthread_mutex_t	*forks;
	pthread_mutex_t	monitor_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	lock;

	pthread_t		monitor;
}					t_data;

/*-------------functions-------------*/

// utils :

int					ft_atoi(const char *str);
size_t				get_time(void);
int					is_pos_int(char *str, int flag);
void				print_data(t_data *data);
void				free_data(t_data *data);
void				t_print(char *str, t_philo *philo);

// main :

bool				init(t_data *data, int ac, char **av);
bool				wakeup_philos(t_data *data);
//int					check_routine(t_philo *philo);
bool				check_routine(t_data *data);
void				*monitoring(void *arg);

#endif
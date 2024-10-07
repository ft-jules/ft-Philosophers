/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:43:49 by jules             #+#    #+#             */
/*   Updated: 2024/10/07 11:55:02 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*batman(void *objet)
{
    char *batobjet;

    batobjet = (char *)objet;
	printf(BROWN "Merci pour cette bat-%s\n" RESET, batobjet);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	thread1;
    pthread_t	thread2;

	(void)argc;
	if (argc < 3)
	{
		printf(RED "Donne deux objets ta mere la\n" RESET);
		return (-1);
	}
	pthread_create(&thread1, NULL, batman, (void *)argv[1]);
    pthread_create(&thread2, NULL, batman, (void *)argv[2]);
	pthread_join(thread1, NULL);
	return (0);
}

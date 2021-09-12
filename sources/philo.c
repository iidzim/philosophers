/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:49:52 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/12 18:19:04 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start_routine(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;
	while (1)
	{
		get_forks(p);
		philo_eat(p);
		philo_sleep(p);
		philo_think(p);
		if (stop_simulation(p))
			break;
	}
	return (NULL);
}

int	create_philo(t_data *data)
{
	int	i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->nbr_philo);
	i = -1;
	while (++i < data->nbr_philo)
	{
		philo[i].time = gettime();
		philo[i].id = i;
		philo[i].data = data;
		philo[i].nbr_time_eat = 0;
		if (pthread_create(&(philo[i].id_thread), NULL, start_routine, &philo[i].id) == -1)
		{
			perror("Error:");
			return (EXIT_FAILURE);
		}
	}
	i = -1;
	while (++i < data->nbr_philo)
	{
		pthread_join(philo[i].id_thread, NULL);//!useless
		// ? while 1 loop -> stop simulation
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc == 5 || argc == 6) && valid_args(argv))
	{
		if (!init_data(&data, argv) && !init_mutex(&data))
		{
			create_philo(&data);
			
		}
		return (0);
	}
	printf("Error\nusage : number_of_philosophers time_to_die time_to_eat\
		time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (1);
}


//* print lock
//? print msg + lock mutex
//? if a philo die -lock_mutex- don't unlock & exit

//* fix ft_usleep
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:49:52 by iidzim            #+#    #+#             */
/*   Updated: 2021/07/17 11:44:31 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start_routine(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;
	while (1)
	{
		get_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (stop_simulation(philo))
			break;
	}
	return NULL;
}

void	create_philo(t_data *data)
{
	int	i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->nbr_philo);
	i = -1;
	while (++i < data->nbr_philo)
	{
		philo[i].id = i;
		philo[i].data = data;
		pthread_create(&(philo[i].id_thread), NULL, start_routine, &philo[i]);
		pthread_join(philo[i].id_thread, NULL);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.time = gettime();
	if ((argc == 5 || argc == 6) && valid_args(argv))
	{
		if (!init_data(&data, argv) && !init_mutex(&data))
		{
			create_philo(&data);
			
		}
		return (0);
	}
	printf("usage : number_of_philosophers time_to_die time_to_eat\
		time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (1);
}

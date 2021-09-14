/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:49:52 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/14 15:19:27 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start_routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		get_forks(p);
		philo_eat(p);
		philo_sleep(p);
		philo_think(p);
	}
	return (NULL);
}

int	stop_simulation(t_philo *p, t_data *data)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->nbr_philo)
		{
			if (data->time_to_die <= (int)(gettime() - p[i].last_time_eat))
			{
				// pthread_mutex_lock(&(p[i].eat));
				// print_state(&p[i], DEAD);
				// pthread_mutex_lock(&(p[i].eat));
				// return (1);
				return (print_state(&p[i], DEAD));
			}
		}
	}
	return (0);
}

int	create_philo(t_data *data)
{
	int		i;
	t_philo	*p;

	p = malloc(sizeof(t_philo) * data->nbr_philo);
	i = -1;
	data->time = gettime();
	while (++i < data->nbr_philo)
	{
		p[i].id = i;
		p[i].data = data;
		p[i].nbr_time_eat = 0;
		p[i].last_time_eat = gettime();
		pthread_mutex_init(&(p[i].eat), NULL);
		if (pthread_create(&(p[i].id_thread), NULL, start_routine, &p[i].id)
			== -1)
		{
			perror("Error:");
			return (EXIT_FAILURE);
		}
	}
	stop_simulation(p, data);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc == 5 || argc == 6) && valid_args(argv))
	{
		if (!init_data(&data, argv) && !init_mutex(&data))
			create_philo(&data);
		return (0);
	}
	printf("Error\nusage : number_of_philosophers time_to_die time_to_eat\
		time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (1);
}

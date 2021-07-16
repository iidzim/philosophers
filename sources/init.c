/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:39:45 by iidzim            #+#    #+#             */
/*   Updated: 2021/07/16 19:45:09 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_data(t_data *d, char **argv)
{
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		printf("Error: Do not test with time_to_die or time_to_eat or time_to_sleep under 60 ms\n");
		return (EXIT_FAILURE);
	}
	d->nbr_philo = ft_atoi(argv[1]);
	if (d->nbr_philo == 0)
	{
		printf("Error: must be at least one philosopher to start\n");
		return (EXIT_FAILURE);
	}
	d->time_to_die = ft_atoi(argv[2]);
	d->time_to_eat = ft_atoi(argv[3]);
	d->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		d->nbr_must_eat_philo = ft_atoi(argv[5]);
		if (d->nbr_must_eat_philo == 0)
			return (EXIT_FAILURE);
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->lock, NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	i = -1;
	while (++i < data->nbr_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	return (0);
}

int	valid_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

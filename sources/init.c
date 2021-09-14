/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:39:45 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/14 15:11:30 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_data(t_data *d, char **av)
{
	d->nbr_philo = ft_atoi(av[1]);
	if (d->nbr_philo == 0)
	{
		printf("Error:\nmust be at least one philosopher to start\n");
		return (EXIT_FAILURE);
	}
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
	{
		printf("Error:\nDo not test with value under 60 ms\n");
		return (EXIT_FAILURE);
	}
	d->time_to_die = ft_atoi(av[2]);
	d->time_to_eat = ft_atoi(av[3]);
	d->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		d->nbr_must_eat_philo = ft_atoi(av[5]);
		if (d->nbr_must_eat_philo == 0)
			return (EXIT_FAILURE);
	}
	else
		d->nbr_must_eat_philo = -1;
	return (EXIT_SUCCESS);
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

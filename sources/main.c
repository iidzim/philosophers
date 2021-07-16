/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:49:52 by iidzim            #+#    #+#             */
/*   Updated: 2021/07/13 13:01:21 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

void	*start_routine(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;
	while (1)
	{
		//?
	}
	return NULL;
}

void	create_philo(t_data *d)
{
	int	i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * d->nbr_philo);
	i = -1;
	while (++i < d->nbr_philo)
	{
		philo[i].id = i;
		philo[i].data = d;
		printf("time to die = %d\n", philo[i].data->time_to_die);
		pthread_create(&philo[i].id_thread, NULL, start_routine, &philo[i]);
	}
}

int	main(int argc, char **argv)
{
	t_data	d;

	gettime();
	if ((argc == 5 || argc == 6) && valid_args(argv))
	{
		if (!init_data(&d, argv) && !init_mutex(&d))
		{
			create_philo(&d);
	}
	else
	{
		printf("usage : number_of_philosophers time_to_die time_to_eat\
	time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	return (0);
}

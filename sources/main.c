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

// void	*test(void *args)
// {
// 	sleep(1);
// 	printf("hi\n");
// 	return (NULL);
// }

// int main (void)
// {
// 	pthread_t t;
// 	printf("before thread\n");
// 	pthread_create(&t, NULL, test, NULL);
// 	pthread_join(t, NULL);
// 	printf("after thread\n");
// 	exit(0);
// }

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

void	init_data(t_data *d, char **argv)
{
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		printf("Do not test with time_to_die or time_to_eat or time_to_sleep under 60 ms\n");
		exit(1);
	}
	d->nbr_philo = ft_atoi(argv[1]);
	d->time_to_die = ft_atoi(argv[2]);
	d->time_to_eat = ft_atoi(argv[3]);
	d->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		d->nbr_must_eat_philo = ft_atoi(argv[5]);
}

void	*start_routine(void *philosopher)
{
	t_philo *philo;

	philo = (t_philo *)philosopher;
	
}

void	create_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->nbr_philo)
	{
		pthread_create(&philo->id, NULL, start_routine, &philo);
	}
}

int	main(int argc, char **argv)
{
	t_data	d;
	t_philo	philo;

	(void)philo;
	// gettime();
	if ((argc == 5 || argc == 6) && valid_args(argv))
	{
		init_data(&d, argv);
		//create threads
		printf("ok\n");
	}
	else
	{
		printf("usage : number_of_philosophers time_to_die time_to_eat\
	time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	return (0);
}

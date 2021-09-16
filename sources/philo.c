/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:49:52 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/16 10:01:39 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start_routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	p->time = gettime();
	p->last_time_eat = p->time;
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
	int	flag;

	flag = 0;
	i = -1;
	while (++i < data->nbr_philo)
	{
		pthread_mutex_lock(&(p[i].eat));
		if (p[i].is_eating == 0 && data->time_to_die <= (int)(gettime()
			- p[i].last_time_eat - 5))
			return (print_state(&p[i], DEAD));
		if (data->nbr_must_eat_philo != -1
			&& p[i].nbr_time_eat >= data->nbr_must_eat_philo)
			flag += 1;
		else
			flag = 0;
		pthread_mutex_unlock(&(p[i].eat));
	}
	if (flag >= data->nbr_philo)
	{
		pthread_mutex_lock(&(p->data->lock));
		return (0);
	}
	return (1);
}

int	create_philo(t_data *data)
{
	t_philo	*p;
	int		i;

	p = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!p)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < data->nbr_philo)
	{
		p[i].id = i;
		p[i].data = data;
		p[i].nbr_time_eat = 0;
		p[i].is_eating = 0;
		pthread_mutex_init(&(p[i].eat), NULL);
		if (pthread_create(&(p[i].id_thread), NULL, start_routine, &p[i].id)
			== -1)
		{
			perror("Error:");
			return (EXIT_FAILURE);
		}
	}
	usleep(100);
	while (stop_simulation(p, data))
		;
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if ((argc == 5 || argc == 6) && valid_args(argv))
	{
		if (!init_data(data, argv) && !init_mutex(data))
			create_philo(data);
		return (0);
	}
	printf("Error\nusage : number_of_philosophers time_to_die time_to_eat\
		time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (1);
}

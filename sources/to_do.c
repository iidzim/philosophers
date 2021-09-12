/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:41:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/12 18:30:22 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_forks(t_philo *p)
{
	int	nbr_philo;

	nbr_philo = p->data->nbr_philo;
	if ((p->id % 2)  == 0)
	{
		pthread_mutex_lock(&(p->data->forks[p->id]));
		printf("%llu\t%d has taken a fork right -p\n", gettime() - p->time, p->id);
		pthread_mutex_lock(&(p->data->forks[(p->id + 1) % nbr_philo]));
		printf("%llu\t%d has taken a fork left -p\n", gettime() - p->time, p->id);
	}
	else
	{
		pthread_mutex_lock(&(p->data->forks[(p->id + 1) % nbr_philo]));
		printf("%llu\t%d has taken a fork left -u\n", gettime() - p->time, p->id);
		pthread_mutex_lock(&(p->data->forks[p->id]));
		printf("%llu\t%d has taken a fork right -u\n", gettime() - p->time, p->id);
	}
	return (0);
}

int philo_eat(t_philo *p)
{
	// pthread_mutex_lock(&(p->data->lock));
	// printf("%llu\t%d is eating\n", gettime() - p->time, p->id);
	// pthread_mutex_unlock(&(p->data->lock));
	print_state(p, 0);
	ft_usleep(p->data->time_to_eat);
	p->last_time_eat = gettime();
	p->nbr_time_eat += 1;
	pthread_mutex_unlock(&(p->data->forks[p->id]));
	pthread_mutex_unlock(&(p->data->forks[(p->id + 1) % p->data->nbr_philo]));
	return (0);
}

int philo_sleep(t_philo *p)
{
	// pthread_mutex_lock(&(p->data->lock));
	// printf("%llu\t%d is sleeping\n", gettime()- p->time, p->id);
	// pthread_mutex_unlock(&(p->data->lock));
	print_state(p, 1);
	ft_usleep(p->data->time_to_sleep);
	return (0);
}

int philo_think(t_philo *p)
{
	// pthread_mutex_lock(&(p->data->lock));
	// printf("%llu\t%d is thinking\n", gettime() - p->time, p->id);
	// pthread_mutex_unlock(&(p->data->lock));
	print_state(p, 2);
	return (0);
}

int	stop_simulation(t_philo *p)
{
	printf("%d - %d\n", p->data->nbr_must_eat_philo, p->nbr_time_eat);
	if (p->data->nbr_must_eat_philo <= p->nbr_time_eat)
	{
		printf("stop simulation\n");
		return (1);
	}
	if (p->data->time_to_die <= (int)(gettime() - p->last_time_eat))
	{
		print_state(p, 3);
		return (1);
	}
	return (0);
}

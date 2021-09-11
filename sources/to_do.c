/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:41:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/11 18:22:36 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_forks(t_philo *p)
{
	//* get right fork then the left one
	int	i;

	i = 0;
	while (i < p->data->nbr_philo)
	{
		if ((i % 2)  == 0)
		{
			pthread_mutex_lock(&(p->data->forks[i]));// right fork
			printf("%d has taken a fork right -p\n", p->id);
			if (i == 0)
				pthread_mutex_lock(&(p->data->forks[p->data->nbr_philo - 1]));
			printf("%d has taken a fork left -p\n", p->id);
			return (i);
		}
		else
		{
			printf("impair !!\n");
			pthread_mutex_lock(&(p->data->forks[i - 1]));
			printf("%d has taken a fork left -u\n", p->id);
			pthread_mutex_lock(&(p->data->forks[i]));
			printf("%d has taken a fork right -u\n", p->id);
			return (i);
		}
		i++;
		// pthread_mutex_lock(&(p->data->forks[i]));
		// pthread_mutex_unlock(&(p->data->forks[i]));
	}
	// printf("time >>>> %llu milliseconds\n", gettime() * 1000);
	return (0);
}

int philo_eat(t_philo *p)
{
	// printf("function: eat[%llu]\n", gettime() - p->data->time);
	pthread_mutex_lock(&(p->data->lock));
	printf("current time = %llu\n", gettime());
	printf("time = %llu\n", p->time);
	printf("%llu\t%d is eating\n", gettime() - p->time, p->id);
	ft_usleep(p->data->time_to_eat);
	printf("time = %llu\n", gettime() - p->time);
	// printf("here\n");
	pthread_mutex_unlock(&(p->data->lock));
	p->last_time_eat = gettime();
	p->nbr_time_eat += 1;
	return (0);
}

int	free_forks(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->data->nbr_philo)
	{
		if ((i % 2) == 0)
			pthread_mutex_unlock(&(p->data->forks[i]));
		else
			pthread_mutex_unlock(&(p->data->forks[i - 1]));
		i++;
	}
	return (0);
}

int philo_sleep(t_philo *p)
{
	// printf("function: sleep[%llu]\n", gettime() - p->data->time);
	pthread_mutex_lock(&(p->data->lock));
	printf("%llu\t%d is sleeping\n", gettime()- p->time, p->id);
	ft_usleep(p->data->time_to_sleep);
	pthread_mutex_unlock(&(p->data->lock));
	return (0);
}

int philo_think(t_philo *p)
{
	// printf("function: think[%llu]\n", gettime() - p->data->time);
	pthread_mutex_lock(&(p->data->lock));
	printf("%llu\t%d is thinking\n", gettime() - p->time, p->id);
	pthread_mutex_unlock(&(p->data->lock));
	return (0);
}

int	stop_simulation(t_philo *p)
{
	if (p->data->nbr_must_eat_philo <= p->nbr_time_eat)
	{
		// printf("stop\n");
		return (-1);
	}
	if (p->data->time_to_die <= (int)(gettime() - p->last_time_eat))
	{
		// printf("stop\n");
		return (-1);
	}
	return (0);
}

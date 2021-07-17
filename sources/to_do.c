/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:41:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/07/17 11:42:58 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_forks(t_philo *philo)
{
	(void)philo;
	//? get_forks left & right
	printf("get_forks\n");
	return (0);
}

int philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	printf("%ld\t%d is eating\n", gettime() - philo->data->time, philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	usleep(philo->data->time_to_eat);
	philo->last_time_eat = gettime();
	philo->nbr_time_eat += 1;
	return (0);
}

int philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	printf("%ld\t%d is sleeping\n", gettime() - philo->data->time, philo->id);
	usleep(philo->data->time_to_sleep);
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}

int philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	printf("%ld\t%d is thinking\n", gettime() - philo->data->time, philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}

int	stop_simulation(t_philo *p)
{
	if (p->data->nbr_must_eat_philo <= p->nbr_time_eat)
		return (-1);
	if (p->data->time_to_die <= (gettime() - p->last_time_eat))
		return (-1);
	return (0);
}

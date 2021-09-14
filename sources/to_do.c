/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:41:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/14 15:18:19 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_forks(t_philo *p)
{
	int	nbr_philo;

	nbr_philo = p->data->nbr_philo;
	if ((p->id % 2) == 0)
	{
		pthread_mutex_lock(&(p->data->forks[p->id]));
		printf("%llu\t%d has taken a fork\n", gettime() - p->data->time, p->id);
		pthread_mutex_lock(&(p->data->forks[(p->id + 1) % nbr_philo]));
		printf("%llu\t%d has taken a fork\n", gettime() - p->data->time, p->id);
	}
	else
	{
		pthread_mutex_lock(&(p->data->forks[(p->id + 1) % nbr_philo]));
		printf("%llu\t%d has taken a fork\n", gettime() - p->data->time, p->id);
		pthread_mutex_lock(&(p->data->forks[p->id]));
		printf("%llu\t%d has taken a fork\n", gettime() - p->data->time, p->id);
	}
}

void	philo_eat(t_philo *p)
{
	// pthread_mutex_lock(&(p->eat));
	print_state(p, EAT);
	ft_usleep(p->data->time_to_eat);
	// pthread_mutex_unlock(&(p->eat));
	p->last_time_eat = gettime();
	p->nbr_time_eat += 1;
	pthread_mutex_unlock(&(p->data->forks[p->id]));
	pthread_mutex_unlock(&(p->data->forks[(p->id + 1) % p->data->nbr_philo]));
}

void	philo_sleep(t_philo *p)
{
	print_state(p, SLEEP);
	ft_usleep(p->data->time_to_sleep);
}

void	philo_think(t_philo *p)
{
	print_state(p, THINK);
}

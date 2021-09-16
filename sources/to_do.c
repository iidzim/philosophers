/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:41:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/16 10:01:21 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_forks(t_philo *p)
{
	int	n;

	n = (p->id + 1) % p->data->nbr_philo;
	if ((p->id % 2) == 0)
	{
		pthread_mutex_lock(&(p->data->forks[p->id]));
		print_state(p, FORK);
		pthread_mutex_lock(&(p->data->forks[n]));
		print_state(p, FORK);
	}
	else
	{
		pthread_mutex_lock(&(p->data->forks[n]));
		print_state(p, FORK);
		pthread_mutex_lock(&(p->data->forks[p->id]));
		print_state(p, FORK);
	}
}

void	philo_eat(t_philo *p)
{
	int	n;

	pthread_mutex_lock(&(p->eat));
	p->last_time_eat = gettime();
	p->is_eating = 1;
	p->nbr_time_eat += 1;
	pthread_mutex_unlock(&(p->eat));
	print_state(p, EAT);
	ft_usleep(p->data->time_to_eat);
	n = (p->id + 1) % p->data->nbr_philo;
	pthread_mutex_unlock(&(p->data->forks[p->id]));
	pthread_mutex_unlock(&(p->data->forks[n]));
	pthread_mutex_lock(&(p->eat));
	p->is_eating = 0;
	pthread_mutex_unlock(&(p->eat));
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

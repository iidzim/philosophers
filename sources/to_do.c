/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:41:25 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/13 12:36:14 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_forks(t_philo *p)
{
	int	nbr_philo;

	nbr_philo = p->data->nbr_philo;
	if ((p->id % 2)  == 0)
	{
		pthread_mutex_lock(&(p->data->forks[p->id]));
		printf("%llu\t%d has taken a fork right\n", gettime() - p->time, p->id);
		pthread_mutex_lock(&(p->data->forks[(p->id + 1) % nbr_philo]));
		printf("%llu\t%d has taken a fork left\n", gettime() - p->time, p->id);
	}
	else
	{
		pthread_mutex_lock(&(p->data->forks[(p->id + 1) % nbr_philo]));
		printf("%llu\t%d has taken a fork left\n", gettime() - p->time, p->id);
		pthread_mutex_lock(&(p->data->forks[p->id]));
		printf("%llu\t%d has taken a fork right\n", gettime() - p->time, p->id);
	}
}

void	philo_eat(t_philo *p)
{
	print_state(p, EAT);
	ft_usleep(p->data->time_to_eat);
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

int	stop_simulation(t_philo *p)
{
	printf("%d - %d\n", p->data->nbr_must_eat_philo, p->nbr_time_eat);
	if (p->data->nbr_must_eat_philo <= p->nbr_time_eat)
	{
		printf("stop simulation\n");
		return (1);
	}
	if (p->data->time_to_die <= (int)(gettime() - p->last_time_eat))
		return (print_state(p, DEAD));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:41:20 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/13 18:08:05 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *str)
{
	int		signe;
	long	x;

	signe = 1;
	x = 0;
	while (*str != '\0' && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str != '\0' && *str >= 48 && *str <= 57)
	{
		x = (x * 10) + ((char)*str - '0');
		if (x > 4294967296)
		{
			if (signe > 0)
				return (-1);
			return (0);
		}
		str++;
	}
	return (x * signe);
}

int	ft_isdigit(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' && s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

unsigned long long	gettime()
{
	struct	timeval current_time;
	unsigned long long	time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time);
}

int	ft_usleep(int time)
{
	unsigned long long curr_time;

	curr_time = gettime();
	while ((int)(gettime() - curr_time) < time)
		usleep(10);
	return (0);
}

int	print_state(t_philo *p, int i)
{
	pthread_mutex_lock(&(p->data->lock));
	if (i == 0)
		printf("%llu\t%d is eating\n", gettime() - p->time, p->id);
	else if (i == 1)
		printf("%llu\t%d is sleeping\n", gettime()- p->time, p->id);
	else if (i == 2)
		printf("%llu\t%d is thinking\n", gettime() - p->time, p->id);
	else
	{
		printf("%llu\t%d died\n", gettime() - p->time, p->id);
		return (1);
	}
	pthread_mutex_unlock(&(p->data->lock));
	return (0);
}

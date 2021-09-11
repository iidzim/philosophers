/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:41:20 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/11 18:21:15 by iidzim           ###   ########.fr       */
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
	// printf("seconds = %ld - microseconds = %d\n", current_time.tv_sec, current_time.tv_usec);
	time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	// printf("time >> %llu milliseconds\n", time);
	return (time);
}

int	ft_usleep(int time)
{
	// printf("time = %d\n", time);
	usleep(time);
	return (0);
}

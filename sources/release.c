/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:45:38 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/15 11:22:21 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	(void)data;
	while (++i < data->nbr_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(data->forks);
	pthread_mutex_destroy(&(data->lock));
	return (0);
}

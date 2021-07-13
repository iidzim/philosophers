/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:05:10 by iidzim            #+#    #+#             */
/*   Updated: 2021/07/13 11:43:45 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
    int nbr_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nbr_must_eat_philo;
    int time;
}               t_data;

typedef struct s_philo
{
    pthread_t   id;
    t_data      *data;
    int         last_time_eat;
    int         nbr_time_eat;
}               t_philo;

/*
** utils.c
*/
int	ft_atoi(const char *str);
int	ft_isdigit(char	*s);

#endif
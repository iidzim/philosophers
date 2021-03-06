/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:05:10 by iidzim            #+#    #+#             */
/*   Updated: 2021/09/14 16:06:01 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DEAD 3
# define FORK 4

typedef struct s_data
{
	int					nbr_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nbr_must_eat_philo;
	unsigned long long	time;
	pthread_mutex_t		lock;
	pthread_mutex_t		*forks;
}					t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			id_thread;
	t_data				*data;
	unsigned long long	last_time_eat;
	int					nbr_time_eat;
	unsigned long long	time;
	pthread_mutex_t		eat;
	int					is_eating;
}				t_philo;

/*
** utils.c
*/
int					ft_atoi(const char *str);
int					ft_isdigit(char	*s);
unsigned long long	gettime(void);
int					ft_usleep(int time);
int					print_state(t_philo *p, int i);

/*
** init.c
*/
int					init_data(t_data *d, char **argv);
int					init_mutex(t_data *data);
int					valid_args(char **argv);

/*
** to_do.c
*/
void				get_forks(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_think(t_philo *philo);
// int		stop_simulation(t_philo *p);

/*
** release.c
*/
int					destroy_mutex(t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:49:52 by iidzim            #+#    #+#             */
/*   Updated: 2021/07/12 11:07:48 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void *args)

	sleep(1);
	printf("hi\n");
	return (NULL);
}

int main (void)
{
	pthread_t t;
	printf("before thread\n");
	pthread_create(&t, NULL, test, NULL);
	pthread_join(t, NULL);
	printf("after thread\n");
	exit(0);
}

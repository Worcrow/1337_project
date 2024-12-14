/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:25 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/12 13:02:19 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		if (dead_loop(philo))
			return (0);
		usleep(500);
	}
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error("gettimeofday() error\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		error("Wrong argument count\n");
	init_data(&data, philos, forks, argv);
	thread_create(&data, forks);
	destory_all(NULL, &data, forks);
	return (0);
}

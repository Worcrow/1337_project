/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:14:21 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/12 13:02:19 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (*philo->dead)
		return (pthread_mutex_unlock(&philo->data->dead_lock), 1);
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1, philo);
	while (!dead_loop(philo))
	{
		eat(philo);
		print_message("is sleeping", philo, philo->id);
		ft_usleep(philo->data->time_to_sleep, philo);
		think(philo);
	}
	return (pointer);
}

int	thread_create(t_data *data, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, data->philos) != 0)
		destory_all("Thread creation error", data, forks);
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine,
				&data->philos[i]) != 0)
			destory_all("Thread creation error", data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destory_all("Thread join error", data, forks);
	while (i < data->num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			destory_all("Thread join error", data, forks);
		i++;
	}
	return (0);
}

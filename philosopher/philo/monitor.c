/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:16:45 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 09:12:31 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->write_lock);
	time = get_current_time() - data->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(&data->write_lock);
}

bool	is_dead(t_philo *philo, size_t time_to_die)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(&data->meal_lock), true);
	pthread_mutex_unlock(&data->meal_lock);
	return (false);
}

int	check_if_dead(t_philo *philos)
{
	int		i;
	t_data	*data;

	i = 0;
	data = philos->data;
	while (i < data->num_of_philos)
	{
		if (is_dead(&philos[i], data->time_to_die))
		{
			print_message("died", &philos[i], philos[i].id);
			pthread_mutex_lock(&data->dead_lock);
			*philos->dead = true;
			pthread_mutex_unlock(&data->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_philo *philos)
{
	int		i;
	int		finished_eating;
	t_data	*data;

	i = 0;
	finished_eating = 0;
	data = philos->data;
	if (data->num_times_to_eat == -1)
		return (0);
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(&data->meal_lock);
		if (philos[i].meals_eaten == data->num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(&data->meal_lock);
		i++;
	}
	if (finished_eating == data->num_of_philos)
	{
		pthread_mutex_lock(&data->dead_lock);
		*philos->dead = true;
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	while (1)
		if (check_if_dead(philos) || check_if_all_ate(philos))
			break ;
	return (pointer);
}

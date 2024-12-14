/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:14:46 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 08:49:34 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_input(t_data *data, char *argv[])
{
	data->num_of_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (data->time_to_die < 60 || data->time_to_eat < 60 \
		|| data->time_to_sleep < 60 || data->num_of_philos > PHILO_MAX)
		error("Invalid Arguments\n");
	if (argv[5])
	{
		data->num_times_to_eat = ft_atol(argv[5]);
		if (data->num_times_to_eat < 0)
			error("Invalid Arguments\n");
		else if (data->num_times_to_eat == 0)
			exit(0);
	}
	else
		data->num_times_to_eat = -1;
}

static void	init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].dead = &data->dead;
		philos[i].last_meal = get_current_time();
		philos[i].data = data;
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[data->num_of_philos - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
	}
}

static void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_data(t_data *data, t_philo *philos, \
pthread_mutex_t *forks, char *argv[])
{
	init_input(data, argv);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	data->start_time = get_current_time();
	data->philos = philos;
	data->dead = false;
	init_forks(forks, data->num_of_philos);
	init_philos(philos, data, forks);
}

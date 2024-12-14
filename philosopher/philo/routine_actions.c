/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:14:29 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 08:50:30 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo, philo->id);
	if (data->num_of_philos == 1)
	{
		ft_usleep(data->time_to_die, philo);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print_message("is eating", philo, philo->id);
	pthread_mutex_lock(&data->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meal_lock);
	ft_usleep(data->time_to_eat, philo);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

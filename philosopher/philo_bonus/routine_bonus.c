/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 04:34:10 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 08:43:38 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	grab_forks(t_philo *philo)
{
	sem_wait(philo->left_fork);
	print_state("has taken a fork", philo);
	sem_wait(philo->right_fork);
	print_state("has taken a fork", philo);
}

static void	puts_forks(t_philo *philo)
{
	sem_post(philo->left_fork);
	sem_post(philo->right_fork);
}

static void	ft_sleep(t_philo *philo)
{
	print_state("is sleeping", philo);
	ft_usleep(philo->data->sleep_time, philo);
}

bool	is_dead(t_philo *philo)
{
	bool	ret;

	sem_wait(philo->data->death);
	ret = philo->dead;
	sem_post(philo->data->death);
	return (ret);
}

void	philo_job(t_philo *philo)
{
	pthread_create(&philo->pt_time, NULL, &check_time, philo);
	if (philo->philo_id % 2 == 0)
		ft_usleep(1, philo);
	while (1)
	{
		if (is_dead(philo) || philo->full)
			break ;
		(grab_forks(philo), sem_wait(philo->data->time));
		philo->last_meal = get_time(0);
		sem_post(philo->data->time);
		print_state("is eating", philo);
		ft_usleep(philo->data->eat_time, philo);
		sem_wait(philo->data->time);
		philo->eaten_num++;
		(sem_post(philo->data->time), puts_forks(philo));
		if (philo->eaten_num == philo->data->nb_meals)
		{
			philo->full = true;
			sem_post(philo->data->finished);
		}
		ft_sleep(philo);
		print_state("is thinking", philo);
	}
	pthread_join(philo->pt_time, NULL);
}

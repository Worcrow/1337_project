/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:51:36 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 09:34:04 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	f_unlink(t_philo **philo)
{
	size_t	i;

	sem_unlink("/death");
	sem_unlink("/kill");
	sem_unlink("/time");
	sem_unlink("/mutex");
	sem_unlink("/finished");
	if (philo != NULL)
	{
		sem_close((*philo)->data->death);
		sem_close((*philo)->data->kill_all);
		sem_close((*philo)->data->time);
		sem_close((*philo)->data->mutex);
		sem_close((*philo)->data->finished);
		i = 0;
		while ((*philo)->data->forks && i < (*philo)->data->nbr)
		{
			sem_close((*philo)->data->forks[i]);
			++i;
		}
	}
}

size_t	get_time(size_t delta_time)
{
	struct timeval	restrict_tp;
	size_t			ret;

	gettimeofday(&restrict_tp, NULL);
	ret = (size_t)(restrict_tp.tv_sec * 1000 + restrict_tp.tv_usec / 1000);
	ret = ret - delta_time;
	return (ret);
}

void	print_state(char *str, t_philo *philo)
{
	sem_wait(philo->data->death);
	if (philo->dead)
		return ;
	printf("%ld %ld %s\n", get_time(philo->data->start_time), \
	philo->philo_id, str);
	sem_post(philo->data->death);
}

void	*check_time(void *arg)
{
	t_philo	*philo;
	size_t	death;

	philo = (t_philo *)arg;
	ft_usleep(10, philo);
	while (!philo->data->close_all)
	{
		sem_wait(philo->data->time);
		death = get_time(philo->last_meal);
		if (death > philo->data->death_time)
		{
			print_state("died", philo);
			philo->dead = true;
			sem_post(philo->data->kill_all);
			sem_wait(philo->data->death);
			return (NULL);
		}
		sem_post(philo->data->time);
	}
	return (NULL);
}

void	*all_ate(void *arg)
{
	t_philo	*philo;
	size_t	i;

	philo = (t_philo *)arg;
	i = 0;
	while (++i <= philo->data->nbr)
	{
		sem_wait(philo->data->finished);
		sem_wait(philo->data->mutex);
		if (philo->data->close_all == 1)
			return (NULL);
		sem_post(philo->data->mutex);
	}
	sem_post(philo->data->kill_all);
	return (NULL);
}

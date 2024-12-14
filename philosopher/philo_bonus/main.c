/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:50:58 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 08:35:52 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_create(t_philo **arg)
{
	t_philo		*philo;
	size_t		i;

	philo = *arg;
	i = 0;
	while (i < philo->data->nbr)
	{
		philo->philo_pid = fork();
		if (philo->philo_pid < 0)
			return (print_error("Error\nduring child creation\n"), 1);
		if (philo->philo_pid == 0)
			philo_job(philo);
		philo = philo->next;
		i++;
	}
	return (0);
}

void	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = get_time(0);
	while (get_time(start) < milliseconds)
	{
		if (philo && is_dead(philo))
			return ;
		usleep(500);
	}
}

void	kill_all(t_philo *philo)
{
	size_t	i;

	i = 0;
	sem_wait(philo->data->kill_all);
	while (++i <= philo->data->nbr)
	{
		kill(philo->philo_pid, SIGKILL);
		philo = philo->next;
	}
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_philo		**philo;

	philo = NULL;
	f_unlink(philo);
	if (ac != 5 && ac != 6)
		print_error("Error!\nwrong number of input\n");
	data = malloc(sizeof(t_data));
	if (!data)
		print_error("Error!\nmalloc failed\n");
	if (set_data(data, av, ac))
		return (free(data), 1);
	philo = malloc(sizeof(t_philo *));
	if (!philo)
		return (free(data), print_error("Error!\nmalloc failed\n"), 1);
	if (set_philo(philo, data) || philo_create(philo))
		return (1);
	pthread_create(&(*philo)->data->pt_finished, NULL, &all_ate, *philo);
	kill_all(*philo);
	sem_wait((*philo)->data->mutex);
	(*philo)->data->close_all = 1;
	sem_post((*philo)->data->mutex);
	sem_post((*philo)->data->finished);
	return (f_unlink(philo), f_lstclear(philo, data->nbr), free(data), 0);
}

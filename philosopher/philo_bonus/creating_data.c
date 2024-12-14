/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:51:27 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 08:30:29 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*create_sem_name(char *sem_name, int nb);

void	create_forks(t_data *list)
{
	size_t	i;

	i = 0;
	list->forks_name = malloc(sizeof(char *) * (list->nbr));
	list->forks = malloc(sizeof(sem_t *) * list->nbr);
	if (!list->forks_name)
		return (free(list));
	while (i < list->nbr)
	{
		list->forks_name[i] = create_sem_name("/forks", i);
		if (!list->forks_name)
			free_forks(list, i);
		sem_unlink(list->forks_name[i]);
		list->forks[i] = sem_open(list->forks_name[i], O_CREAT, 0644, 1);
		++i;
	}
}

int	set_data(t_data *data, char **argv, int argc)
{
	data->nbr = ft_atol(argv[1]);
	data->death_time = ft_atol(argv[2]);
	if (data->nbr == 1)
	{
		ft_usleep(data->death_time * 1000, NULL);
		return (printf("%lu died\n", data->death_time));
	}
	data->eat_time = ft_atol(argv[3]);
	data->sleep_time = ft_atol(argv[4]);
	data->nb_meals = LONG_MAX;
	if (argc == 6)
		data->nb_meals = ft_atol(argv[5]);
	check_args(data, argc);
	data->start_time = get_time(0);
	create_forks(data);
	data->death = sem_open("/death", O_CREAT, 0666, 1);
	data->finished = sem_open("/finished", O_CREAT, 0666, 0);
	data->kill_all = sem_open("/kill", O_CREAT, 0666, 0);
	data->time = sem_open("/time", O_CREAT, 0666, 1);
	data->mutex = sem_open("/mutex", O_CREAT, 0666, 1);
	data->close_all = 0;
	return (0);
}

int	set_philo(t_philo **list, t_data *data)
{
	size_t	i;
	t_philo	*prev;
	t_philo	*temp;

	i = 0;
	prev = NULL;
	while (++i <= data->nbr)
	{
		temp = lst_new(i, data);
		if (!temp)
		{
			f_lstclear(list, i);
			print_error("Error!\nmalloc fail\n");
		}
		if (i == 1)
			*list = temp;
		temp->prev = prev;
		if (i > 1)
			prev->next = temp;
		prev = temp;
	}
	(*list)->prev = prev;
	prev->next = *list;
	return (0);
}

t_philo	*lst_new(size_t i, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (free(data), NULL);
	philo->philo_id = i;
	philo->eaten_num = 0;
	philo->dead = false;
	philo->full = false;
	philo->next = NULL;
	philo->prev = NULL;
	philo->data = data;
	philo->left_fork = philo->data->forks[i - 1];
	philo->right_fork = philo->data->forks[i % philo->data->nbr];
	philo->last_meal = get_time(0);
	return (philo);
}

void	f_lstclear(t_philo **philo, size_t i)
{
	size_t	h;
	t_philo	*temp;
	t_philo	*prev;

	h = 0;
	temp = *philo;
	while (h < i && temp->next != NULL)
	{
		temp = temp->next;
		h++;
	}
	while (h != 0 && temp->prev != NULL)
	{
		prev = temp->prev;
		free(temp);
		temp = prev;
		h--;
	}
	free(philo);
}

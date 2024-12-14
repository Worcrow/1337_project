/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:03:26 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/12 13:03:47 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		write(2, message + i, 1);
	exit(EXIT_FAILURE);
}

static inline int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static inline int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(char *str)
{
	size_t	number;

	number = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error("error! Only positive number allowed\n");
	while (*str)
	{
		if (is_digit(*str))
			number = number * 10 + (*str - '0');
		if (number > LONG_MAX || !is_digit(*str))
			error("number should have only digit and not\
greater than INT MAX\n");
		++str;
	}
	return (number);
}

void	destory_all(char *str, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		++i;
	}
	if (str)
		error(str);
}

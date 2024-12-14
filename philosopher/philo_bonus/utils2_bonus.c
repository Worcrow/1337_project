/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 07:11:44 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 09:37:51 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_args(t_data *list, int argc)
{
	if (list->nbr > 200 || list->death_time < 60
		|| list->eat_time < 60 || list->sleep_time < 60)
		print_error("Error!\nwrong input");
	if (argc == 6 && list->nb_meals < 0)
		print_error("Error!\nwrong input");
	if (argc == 6 && list->nb_meals == 0)
		exit(EXIT_SUCCESS);
}

void	print_error(char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		write(2, message + i, 1);
	exit(EXIT_FAILURE);
}

void	free_forks(t_data *list, int size)
{
	while (size >= 0)
	{
		free(list->forks_name[size]);
		size--;
	}
	free(list->forks_name);
	free(list->forks);
	free(list);
	print_error("Cant' Allocate Memory To Create Forks\n");
}

static inline int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(char *str)
{
	size_t	number;

	number = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		print_error("Error! Only positive number allowed\n");
	while (*str)
	{
		if (is_digit(*str))
			number = number * 10 + (*str - '0');
		if (!is_digit(*str) || number > LONG_MAX)
			print_error("number should have only digit and \
 not greater than INT MAX\n");
		++str;
	}
	return (number);
}

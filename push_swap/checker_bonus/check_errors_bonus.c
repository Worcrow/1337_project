/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 07:50:13 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/04 07:50:28 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/push_swap_bonus.h"

void	send_error(char *message, int err_status)
{
	int	i;

	i = -1;
	while (message[++i])
		write(2, message + i, 1);
	exit(err_status);
}

void	check_isduplicate(int *number_list, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (number_list[i] == number_list[j])
			{
				free(number_list);
				send_error("Error\n", 2);
			}
			j++;
		}
		i++;
	}
}

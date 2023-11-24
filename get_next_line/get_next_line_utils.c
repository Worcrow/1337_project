/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:55:48 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/22 23:15:24 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	buffer_empty(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	starting_index(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i] == 0)
		i++;
	return (i);
}

size_t	count_size(char *buffer)
{
	int		i;
	size_t	len;

	len = 0;
	i = starting_index(buffer);
	if (i >= BUFFER_SIZE)
		return (-1);
	while (i < BUFFER_SIZE && buffer[i] != '\n')
	{
		len++;
		i++;
	}
	len++;
	return (len);
}

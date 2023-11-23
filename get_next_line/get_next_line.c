/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:07:28 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/22 23:11:34 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*result;
	int			index;
	int			i;

	index = 0;
	i = 0;
	if (buffer_empty(buffer) == 1)
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (NULL);
	result = (char *) malloc(sizeof(char) *(count_size(buffer) + 1));
	if (!result)
		return (NULL);
	index = starting_index(buffer);
	while (index < BUFFER_SIZE && buffer[index] != '\n')
	{
		result[i++] = buffer[index];
		buffer[index++] = 0;
	}
	buffer[index] = 0;
	if (index < BUFFER_SIZE)
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

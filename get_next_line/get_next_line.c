/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:02:52 by oel-asri          #+#    #+#             */
/*   Updated: 2023/12/02 05:39:33 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	store[BUFFER_SIZE];
	char		*line;
	size_t		bytes;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, "", 0) < 0)
		return (NULL);
	while (empty_buffer(store) == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (line);
		ft_copy(store, buffer);
		if (!check_nl(store))
			ft_strjoin(&line, store);
	}
	if (empty_buffer(store) == -1 || !ft_strjoin(&line, store))
		return (NULL);
	return (line);
}

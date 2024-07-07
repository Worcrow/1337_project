/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:41:37 by oel-asri          #+#    #+#             */
/*   Updated: 2023/12/14 09:16:22 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*buffer;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp)
		return (free(buffer), buffer = NULL, NULL);
	i = 1;
	while (!ft_strchr(buffer, '\n') && i)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer), free(temp), buffer = NULL, NULL);
		temp[i] = '\0';
		if (!ft_strjoin(&buffer, temp))
			return (NULL);
	}
	free(temp);
	line = get_ln(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	return (buffer = remake_buffer(buffer), line);
}

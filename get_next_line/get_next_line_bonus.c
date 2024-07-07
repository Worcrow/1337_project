/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:33:26 by oel-asri          #+#    #+#             */
/*   Updated: 2023/12/14 09:13:11 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*buffer[OPEN_MAX];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	temp = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	i = 1;
	while (!ft_strchr(buffer[fd], '\n') && i)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer[fd]), free(temp), buffer[fd] = NULL, NULL);
		temp[i] = '\0';
		if (!ft_strjoin(&buffer[fd], temp))
			return (NULL);
	}
	free(temp);
	line = get_ln(buffer[fd]);
	if (!line)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	return (buffer[fd] = remake_buffer(buffer[fd]), line);
}

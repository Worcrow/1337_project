/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:41:37 by oel-asri          #+#    #+#             */
/*   Updated: 2023/12/09 21:42:45 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!res)
	{
		free(str2);
		str2 = NULL;
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str1 && str1[i])
	{
		res[j] = str1[i];
		j++;
		i++;
	}
	i = 0;
	while (str2 && str2[i])
	{
		res[j] = str2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (free(str1), str1 = NULL, res);
}

char	*get_ln(char *buffer)
{
	size_t	i;
	char	*all;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
	   i++;
	if (buffer[i] == '\n')
		i++;
	all = malloc(i + 1);
	if (!all)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		all[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		all[i++] = '\n';
	all[i] = '\0';
	return (all);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*buffer;
	char		*line;
	int			i;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	/**if (!buffer)
		buffer = ft_strdup("");**/
	i = 1;
	while (!ft_strchr(buffer, '\n') && i)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer), free(temp), buffer = NULL, NULL);
		temp[i] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	line = get_ln(buffer);
	buffer = remake_buffer(buffer);
	return (line);
}

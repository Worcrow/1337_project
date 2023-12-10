/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:07:59 by oel-asri          #+#    #+#             */
/*   Updated: 2023/12/09 21:42:56 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	size_t	i;

	dest = malloc(ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	*ft_strchr(const char *src, int c)
{
	size_t	i;

	i = 0;
	while (src && src[i] && src[i] != (char )c)
		i++;
	if (src && src[i] == '\0')
		return (NULL);
	return ((char *)(src + i));
}

char	*remake_buffer(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (i >= ft_strlen(buffer))
		return (free(buffer), buffer = NULL, NULL);
	res = malloc(ft_strlen(buffer) - i + 1);
	if (!res)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	j = 0;
	while (buffer[i])
	{
		res[j] = buffer[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (free(buffer), buffer = NULL, res);
}

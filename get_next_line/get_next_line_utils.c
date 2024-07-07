/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:07:59 by oel-asri          #+#    #+#             */
/*   Updated: 2023/12/11 03:15:48 by oel-asri         ###   ########.fr       */
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

char	*ft_strjoin(char **str1, char *str2)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(ft_strlen(*str1) + ft_strlen(str2) + 1);
	if (!res)
		return (free(*str1), free(str2), *str1 = NULL, str2 = NULL, NULL);
	i = 0;
	j = 0;
	while (*str1 && (*str1)[i])
	{
		res[j] = (*str1)[i];
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
	return (free(*str1), *str1 = res, res);
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
		return (free(buffer), buffer = NULL, NULL);
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

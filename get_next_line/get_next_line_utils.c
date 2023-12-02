/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:30:50 by oel-asri          #+#    #+#             */
/*   Updated: 2023/12/02 05:50:38 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_copy(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && str1 && str2)
	{
		str1[i] = str2[i];
		i++;
	}
}

void	__remake_buffer__(char *buffer)
{
	int	i;
	int	j;

	i = empty_buffer(buffer);
	if (i == -1)
		return ;
	j = 0;
	if (buffer[i] == '\n')
		buffer[i] = 0;
	while (buffer[++i] != '\0' && i < BUFFER_SIZE)
	{
		buffer[j++] = buffer[i];
		buffer[i] = 0;
	}
}

int	empty_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer && i < BUFFER_SIZE)
	{
		if (buffer[i] != 0)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

char	*__realloc__(char **str, char *str2, size_t len1, size_t len2)
{
	char	*temp;
	size_t	i;
	int		add;
	size_t	size;

	add = 0;
	if (str2[len2] == '\n')
		add = 1;
	if (*str == NULL)
		size = len2 + 1 + add;
	else
		size = len1 + len2 + 1 + add;
	temp = malloc(size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len1 && (*str)[i] != '\0')
	{
		temp[i] = (*str)[i];
		i++;
	}
	temp[i] = '\0';
	if (len1 >  0)
		free(*str);
	*str = temp;
	return (temp);
}

int	ft_strjoin(char **str1, char *str2)
{
	size_t	len_str1;
	size_t	len_str2;
	size_t	i;

	if (str2 == NULL)
		return (0);
	len_str1 = ft_strlen(*str1);
	len_str2 = ft_strlen(str2);
	if (!__realloc__(str1, str2, len_str1, len_str2))
		return (0);
	i = 0;
	while (str2[i] != '\0' && str2[i] != '\n')
	{
		(*str1)[len_str1] = str2[i];
		str2[i] = 0;
		i++;
		len_str1++;
	}
	if (str2[i] == '\n')
		(*str1)[len_str1++] = '\n';
	(*str1)[len_str1] = '\0';
	__remake_buffer__(str2);
	return (1);
}

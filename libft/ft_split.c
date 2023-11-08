/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:00:14 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/05 19:24:29 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * count_words - count how many words betwen the char c
 * @s: string to be searched
 * @c: a char delimeter
 * Return: numbers of word
*/

static size_t	count_words(const char *s, int c)
{
	size_t	count;
	size_t	i;
	int		flag;

	flag = 1;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			flag = 1;
		else if (flag)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

/**
 * count_to_deli - count the length of substring between char c
 * @s: string to be seached
 * @c: a char delimeter
 * Return: length of the substring
*/

static size_t	count_to_deli(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] == (char)c)
		i++;
	while (s[i] != '\0' && s[i] != (char) c)
	{
		len++;
		i++;
	}
	return (len);
}

static size_t	copy_to(char *dest, char const *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

static	void	free_mem(char **addr, size_t index)
{
	while (index > 0)
	{
		free(addr[index]);
		index--;
	}
	free(addr[index]);
	free(addr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	result = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	i = 0;
	j = 0;
	while (result && s[i] != '\0')
	{
		if (s[i++] == c)
			continue ;
		result[j] = (char *) malloc(sizeof(char) * \
				(count_to_deli(s + i - 1, c) + 1));
		if (!result[j])
		{
			free_mem(result, j);
			return (0);
		}
		i += copy_to(result[j++], s + i - 1, count_to_deli(s + i - 1, c)) - 1;
	}
	if (result)
		result[j] = NULL;
	return (result);
}

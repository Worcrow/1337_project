/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:43:44 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/04 08:15:00 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/push_swap_bonus.h"

/**
 * count_words - count how many words betwen the char c
 * @s: string to be searched
 * @c: a char delimeter
 * Return: numbers of word
*/

static size_t	count_words(const char *s, size_t *size)
{
	size_t	count;
	size_t	i;
	int		flag;

	flag = 1;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			flag = 1;
		else if (flag)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	*size = count;
	return (count);
}

/**
 * count_to_deli - count the length of substring between char c
 * @s: string to be seached
 * @c: a char delimeter
 * Return: length of the substring
*/

static size_t	count_to_deli(const char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] == ' ')
		i++;
	while (s[i] != '\0' && s[i] != ' ')
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

char	**ft_split(char const *s, size_t *size)
{
	char	**result;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	result = (char **) malloc(sizeof(char *) * (count_words(s, size) + 1));
	i = -1;
	j = 0;
	while (result && s[++i] != '\0')
	{
		if (s[i] == ' ')
			continue ;
		else if (s[i] == '\t')
			send_error("Error\n", 2);
		result[j] = (char *) malloc(sizeof(char) * \
				(count_to_deli(s + i) + 1));
		if (!result[j])
			return (free_arg(result), NULL);
		i += copy_to(result[j++], s + i, count_to_deli(s + i)) - 1;
	}
	if (result)
		result[j] = NULL;
	return (result);
}

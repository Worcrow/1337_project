/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:41:41 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/03 00:58:52 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * check_in - check if the char c in str
 * @str: str to be searched
 * @c: the char to be checked
 * Return: 1 if c not in str, otherwise 0
*/

static int	check_in(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*result;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && check_in(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && check_in(set, s1[end - 1]))
		end--;
	result = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (start < end)
	{
		result[i] = s1[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:36:21 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/05 01:49:55 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	len_s;
	size_t	i;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (!len || start >= len_s)
		return (ft_strdup(""));
	if (len + start > len_s)
		len = len_s - start;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	while (i <= len)
		result[i++] = '\0';
	return (result);
}

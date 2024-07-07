/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:27:54 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/01 13:50:42 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	var;
	char	*temp;

	i = 0;
	var = (char)c;
	temp = (char *) s;
	while (temp && temp[i] != '\0')
	{
		if (temp[i] == var)
			return (temp + i);
		i++;
	}
	if (temp[i] == var)
		return (temp + i);
	return (0);
}

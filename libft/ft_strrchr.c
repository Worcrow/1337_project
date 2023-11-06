/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:55:35 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/01 23:04:16 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	var;
	char	*addr;

	addr = 0;
	var = (char)c;
	while (*s)
	{
		if (*s == var)
			addr = (char *)s;
		s++;
	}
	if (var == '\0')
		addr = (char *)s;
	return (addr);
}

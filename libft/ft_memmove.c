/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:14:07 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/02 18:09:16 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dst;
	const char	*sr;
	size_t		i;

	dst = (char *)dest;
	sr = (const char *)src;
	i = 0;
	if (dst == sr)
		return (dest);
	if (dst > sr && dst < sr + len)
	{
		while (len-- > 0)
			dst[len] = sr[len];
	}
	else
	{
		while (i < len)
		{
			dst[i] = sr[i];
			i++;
		}
	}
	return (dest);
}

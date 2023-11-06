/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:43:35 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/01 22:50:20 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*temp_dst;
	char	*temp_src;
	size_t	i;

	temp_dst = (char *)dst;
	temp_src = (char *)src;
	i = 0;
	while (dst != src && i < n)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}

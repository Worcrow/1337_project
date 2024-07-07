/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:19:03 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/12 12:05:35 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_calloc - allocate space for count of type size
 * @count: number of contiguous block to be allocated
 * @size: size of each block
 * @Return: pointer to the address allocated or Null if fails
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*address;

	if ((long) count < 0 && (long) size < 0)
		return (0);
	address = malloc(count * size);
	if (!address)
		return (0);
	ft_bzero(address, count * size);
	return (address);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:19:03 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/09 05:01:19 by oel-asri         ###   ########.fr       */
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

	address = malloc(count * size);
	if (!address)
		return (0);
	ft_bzero(address, count * size);
	return (address);
}

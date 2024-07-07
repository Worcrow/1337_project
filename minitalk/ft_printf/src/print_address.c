/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:21:21 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/18 21:16:38 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/function_used.h"

int	print_address(void *addr)
{
	uintptr_t	adr;
	int			count;

	adr = (uintptr_t) addr;
	count = print_string("0x") + print_address_hex(adr);
	return (count);
}

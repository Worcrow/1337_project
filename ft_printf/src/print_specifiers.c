/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:22:18 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/18 21:49:29 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/function_used.h"

int	print_specifiers(va_list ap, char type)
{
	int	c;

	c = 0;
	if (type == 'd' || type == 'i')
		c += print_decimal(va_arg(ap, int));
	else if (type == 'u')
		c += print_unsigned_hex_int((unsigned int)va_arg(ap, int), 10, 0);
	else if (type == 'c')
		c += print_char((char )va_arg(ap, int));
	else if (type == 's')
		c += print_string(va_arg(ap, char *));
	else if (type == 'x')
		c += print_unsigned_hex_int(va_arg(ap, int), 16, 0);
	else if (type == 'X')
		c += print_unsigned_hex_int(va_arg(ap, int), 16, 1);
	else if (type == 'p')
		c += print_address(va_arg(ap, char *));
	return (c);
}

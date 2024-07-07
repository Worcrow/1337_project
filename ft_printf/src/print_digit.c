/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 00:19:27 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/18 21:17:04 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/function_used.h"

int	print_decimal(int num)
{
	long int	n;
	int			c;

	n = num;
	c = 0;
	if (n < 0)
	{
		c += print_char('-');
		n *= -1;
	}
	if (n < 10)
		return (c + print_char(n + '0'));
	c += print_decimal(n / 10);
	c += print_char(n % 10 + '0');
	return (c);
}

int	print_unsigned_hex_int(unsigned int num, int base, int is_upper)
{
	char			*symbols;
	int				c;

	c = 0;
	if (is_upper)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (num < (unsigned int )base)
		return (print_char(symbols[num]));
	c += print_unsigned_hex_int(num / base, base, is_upper);
	c += print_char(symbols[num % base]);
	return (c);
}

int	print_address_hex(unsigned long int num)
{
	char	*symbols;
	int		c;

	c = 0;
	symbols = "0123456789abcdef";
	if (num < 16)
		return (print_char(symbols[num]));
	c += print_address_hex(num / 16);
	c += print_char(symbols[num % 16]);
	return (c);
}

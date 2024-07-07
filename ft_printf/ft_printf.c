/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:45:59 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/21 21:27:57 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t		ind;
	int			count;
	va_list		ap;

	ind = 0;
	count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(ap, format);
	while (format[ind] != '\0')
	{
		if (format[ind] == '%')
		{
			if (format[ind + 1] == '%')
				count += print_char('%');
			else
				count += print_specifiers(ap, format[ind + 1]);
			ind++;
		}
		else
			count += print_char(format[ind]);
		ind++;
	}
	va_end(ap);
	return (count);
}

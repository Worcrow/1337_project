/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_used.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 00:42:59 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/18 20:38:14 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_USED_H
# define FUNCTION_USED_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	print_char(char c);
int	print_string(char *str);
int	print_decimal(int num);
int	print_unsigned_hex_int(unsigned int num, int base, int is_upper);
int	print_address_hex(unsigned long int num);
int	print_address(void *addr);
int	print_specifiers(va_list ap, char type);
int	ft_printf(const char *format, ...);
#endif

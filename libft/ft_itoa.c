/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:33:49 by oel-asri          #+#    #+#             */
/*   Updated: 2023/11/03 16:47:42 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * count_digit - count the numbers of digit present in n
 * @n: number to be count it digit
 * @Return: the number of digit present in n
*/

static size_t	count_digit(int n)
{
	size_t		i;
	long int	num;

	i = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		++i;
	}
	while (num > 0)
	{
		num /= 10;
		++i;
	}
	return (i);
}

/**
 * ft_itoa - convert the integer n into string
 * @n: number to be converted
 * @Return: The string representing the integer.NULL if the allocation fails
*/

char	*ft_itoa(int n)
{
	char		*result;
	long int	num;
	size_t		len;
	size_t		end;

	num = n;
	len = count_digit(n);
	end = 0;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		result[0] = '-';
		end = 1;
	}
	result[len] = '\0';
	while (len > end)
	{
		result[--len] = ((num % 10) + '0');
		num /= 10;
	}
	return (result);
}

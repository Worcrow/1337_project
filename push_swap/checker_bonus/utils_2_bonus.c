/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 07:55:57 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/04 07:55:59 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/push_swap_bonus.h"

t_stack	*max(t_stack *stack)
{
	int		nbr;
	t_stack	*max;

	nbr = stack->nbr;
	max = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->nbr > nbr)
		{
			nbr = stack->nbr;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack	*min(t_stack *stack)
{
	int		nbr;
	t_stack	*min;

	nbr = stack->nbr;
	min = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->nbr < nbr)
		{
			nbr = stack->nbr;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

int	ft_strcmp(char *str1, char *str2)
{
	size_t	len_str2;
	size_t	len_str1;
	size_t	i;

	i = 0;
	len_str2 = length(str2);
	len_str1 = length(str1);
	if (len_str1 != 2 && len_str1 != 3)
		return (1);
	while (i < len_str2)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i != len_str1)
		return (1);
	return (0);
}

size_t	length(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

void	initialize_var(long *result, int *sign, int *flag)
{
	*result = 0;
	*flag = 0;
	*sign = 1;
}

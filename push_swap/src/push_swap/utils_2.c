/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 07:57:34 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/04 07:57:37 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	initialize_var(long *result, int *sign, int *flag)
{
	*result = 0;
	*flag = 0;
	*sign = 1;
}

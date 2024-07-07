/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:31:30 by oel-asri          #+#    #+#             */
/*   Updated: 2024/06/21 15:35:35 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*current;
	long		target;
	t_stack		*result;

	while (stack_b)
	{
		current = stack_a;
		target = LONG_MAX;
		while (current)
		{
			if (current->nbr > stack_b->nbr && current->nbr < target)
			{
				target = current->nbr;
				result = current;
			}
			current = current->next;
		}
		if (target == LONG_MAX)
			stack_b->target = min(stack_a);
		else
			stack_b->target = result;
		stack_b = stack_b->next;
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	check_median(stack_a);
	check_median(stack_b);
	set_target(stack_a, stack_b);
}

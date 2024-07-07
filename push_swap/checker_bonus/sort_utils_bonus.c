/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:50:24 by oel-asri          #+#    #+#             */
/*   Updated: 2024/06/21 22:08:12 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/push_swap_bonus.h"

t_stack	*get_cheapest_node(t_stack *stack)
{
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, \
		t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
		rr(stack_a, stack_b);
	check_median(*stack_a);
	check_median(*stack_b);
}

void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, \
		t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
		rrr(stack_a, stack_b);
	check_median(*stack_a);
	check_median(*stack_b);
}

void	prep_for_push(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->is_above_median)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (top->is_above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	set_min_on_top(t_stack **stack)
{
	t_stack	*min_stack;

	min_stack = min(*stack);
	while ((*stack)->nbr != min_stack->nbr)
	{
		if (min_stack->is_above_median)
			ra(stack);
		else
			rra(stack);
	}
}

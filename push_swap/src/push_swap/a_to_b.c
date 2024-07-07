/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:24:00 by oel-asri          #+#    #+#             */
/*   Updated: 2024/06/21 15:31:10 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	check_median(t_stack *stack)
{
	int	median;
	int	index;

	if (!stack)
		return ;
	index = 0;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = index;
		stack->is_cheapest = false;
		if (stack->index <= median)
			stack->is_above_median = true;
		else
			stack->is_above_median = false;
		stack = stack->next;
		++index;
	}
}

void	get_target_from_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head_b;
	t_stack	*target;
	long	match_nbr;

	while (stack_a)
	{
		match_nbr = LONG_MIN;
		head_b = stack_b;
		while (head_b)
		{
			if (head_b->nbr < stack_a->nbr && head_b->nbr > match_nbr)
			{
				match_nbr = head_b->nbr;
				target = head_b;
			}
			head_b = head_b->next;
		}
		if (match_nbr == LONG_MIN)
			stack_a->target = max(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	calcule_push_cost_a(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	while (stack_a)
	{
		if (stack_a->is_above_median)
			stack_a->push_cost = stack_a->index;
		else
			stack_a->push_cost = size_a - stack_a->index;
		if (stack_a->target->is_above_median)
			stack_a->push_cost += stack_a->target->index;
		else
			stack_a->push_cost += size_b - stack_a->target->index;
		stack_a = stack_a->next;
	}
}

void	set_the_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	int		push_cost;

	if (!stack)
		return ;
	push_cost = stack->push_cost;
	cheapest_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->push_cost < push_cost)
		{
			push_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = true;
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	check_median(stack_a);
	check_median(stack_b);
	get_target_from_b(stack_a, stack_b);
	calcule_push_cost_a(stack_a, stack_b);
	set_the_cheapest(stack_a);
}

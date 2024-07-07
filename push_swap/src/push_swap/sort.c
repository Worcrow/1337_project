/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:44:38 by oel-asri          #+#    #+#             */
/*   Updated: 2024/06/21 16:50:12 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	stack = stack->next;
	while (stack)
	{
		if (temp->nbr > stack->nbr)
			return (0);
		temp = temp->next;
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack **stack)
{
	t_stack	*max_node;
	t_stack	*min_node;

	max_node = max(*stack);
	min_node = min(*stack);
	if (max_node == (*stack))
		ra(stack, 1);
	if (max_node == (*stack)->next || min_node == (*stack)->next->next)
		rra(stack, 1);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, 1);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_a);
	if (cheapest_node->is_above_median && \
			cheapest_node->target->is_above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!cheapest_node->is_above_median && \
			!cheapest_node->target->is_above_median)
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target, 'b');
	pb(stack_a, stack_b);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	size_t	len_a;

	if (!(*stack_a))
		return ;
	len_a = stack_size(*stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (len_a-- > 3 && !is_sorted(*stack_a))
	{
		a_to_b(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		b_to_a(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	check_median(*stack_a);
	set_min_on_top(stack_a);
}

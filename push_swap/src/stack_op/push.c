/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:27:23 by oel-asri          #+#    #+#             */
/*   Updated: 2024/06/21 17:29:04 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*node_to_push;

	if (!*stack_src)
		return ;
	node_to_push = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->previous = NULL;
	node_to_push->previous = NULL;
	if (!*stack_dest)
	{
		node_to_push->next = NULL;
		*stack_dest = node_to_push;
	}
	else
	{
		node_to_push->next = *stack_dest;
		node_to_push->next->previous = node_to_push;
		*stack_dest = node_to_push;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
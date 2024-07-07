/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:58:51 by oel-asri          #+#    #+#             */
/*   Updated: 2024/06/21 20:29:27 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/push_swap_bonus.h"

t_stack	*last_node(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

int	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*temp;

	if (!stack)
		return (-1);
	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (-1);
	node->nbr = nbr;
	node->next = NULL;
	if (!(*stack))
	{
		node->previous = NULL;
		(*stack) = node;
	}
	else
	{
		temp = last_node (*stack);
		temp->next = node;
		node->previous = temp;
	}
	return (0);
}

void	init_stack(t_stack **stack, int *number_list, size_t size)
{
	size_t	i;
	int		flag;

	i = 0;
	while (i < size)
	{
		flag = append_node(stack, number_list[i]);
		if (flag == -1)
		{
			free_stack(*stack);
			free(number_list);
			send_error("Can't Allocate Memory\n", 2);
		}
		i++;
	}
}

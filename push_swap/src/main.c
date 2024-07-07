/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:50:58 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/05 06:42:41 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		if (stack_size(*stack_a) == 2)
			sa(stack_a, 1);
		else if (stack_size(*stack_a) == 3)
			sort_three(stack_a);
		else
			sort_stack(stack_a, stack_b);
	}
}

void	print_stack(t_stack *stack, char c)
{
	printf("%c\n", c);
	while (stack)
	{
		printf("%d\n", stack->nbr);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*number_list;
	size_t	size;

	stack_a = NULL;
	stack_b = NULL;
	number_list = NULL;
	size = 0;
	number_list = parse_arg(argc, argv, &size);
	if (size > 0)
	{
		check_isduplicate(number_list, size);
		init_stack(&stack_a, number_list, size);
		sort(&stack_a, &stack_b);
	}
	free(number_list);
	free_stack(stack_a);
	return (0);
}

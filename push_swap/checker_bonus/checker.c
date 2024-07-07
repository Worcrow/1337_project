/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 07:51:01 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/04 08:08:32 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/push_swap_bonus.h"

void	ft_bzero(char *buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void	execute_instruction(char *instruction, t_stack **stack_a, \
		t_stack **stack_b)
{
	if (!ft_strcmp(instruction, "sa"))
		sa(stack_a);
	else if (!ft_strcmp(instruction, "sb"))
		sb(stack_b);
	else if (!ft_strcmp(instruction, "ss"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "ra"))
		ra(stack_a);
	else if (!ft_strcmp(instruction, "rb"))
		rb(stack_b);
	else if (!ft_strcmp(instruction, "rr"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "rra"))
		rra(stack_a);
	else if (!ft_strcmp(instruction, "rrb"))
		rrb(stack_b);
	else if (!ft_strcmp(instruction, "rrr"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "pa"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "pb"))
		pb(stack_a, stack_b);
	else
		send_error("Error\n", 6);
}

void	read_input(t_stack **stack_a, t_stack **stack_b)
{
	char	buffer[5];
	int		i;

	i = -1;
	while (true)
	{
		++i;
		read(1, buffer + i, 1);
		if (i == 0 && buffer[i] == '\0')
			break ;
		else if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			execute_instruction(buffer, stack_a, stack_b);
			i = -1;
			ft_bzero(buffer, 5);
		}
	}
}

int	main(int argc, char **argv)
{
	int		*num_list;
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	size;

	stack_a = NULL;
	stack_b = NULL;
	num_list = NULL;
	size = 0;
	num_list = parse_arg(argc, argv, &size);
	if (size > 0)
	{
		check_isduplicate(num_list, size);
		init_stack(&stack_a, num_list, size);
		read_input(&stack_a, &stack_b);
		if (is_sorted(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free(num_list);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

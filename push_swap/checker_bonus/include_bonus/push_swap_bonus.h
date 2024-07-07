/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 07:54:22 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/04 07:54:26 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct stack
{
	struct stack	*target;
	struct stack	*next;
	struct stack	*previous;
	bool			is_cheapest;
	int				nbr;
	int				index;
	int				push_cost;
	int				is_above_median;
}	t_stack;

char	**ft_split(char const *s, size_t *size);
int		*parse_arg(int argc, char **argv, size_t *size);
void	initialize_var(long *result, int *sign, int *flag);
void	free_stack(t_stack *stack);
t_stack	*ft_lstlast(t_stack *lst);
size_t	stack_size(t_stack *stack);
void	init_stack(t_stack **stack, int *number_list, size_t size);
long	ft_atol(char *s, int *errno);
void	send_error(char *message, int err_status);
void	free_arg(char **argv);
int		is_sorted(t_stack *stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
t_stack	*max(t_stack *stack);
t_stack	*min(t_stack *stack);
void	sort_three(t_stack **stack);
void	a_to_b(t_stack *stack_a, t_stack *stack_b);
t_stack	*get_cheapest_node(t_stack *stack);
void	check_median(t_stack *stack);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, \
		t_stack *cheapest_node);
void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, \
		t_stack *cheapest_node);
void	prep_for_push(t_stack **stack, t_stack *top, char stack_name);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	b_to_a(t_stack *stack_a, t_stack *stack_b);
void	set_min_on_top(t_stack **stack);
void	check_isduplicate(int *number_list, size_t size);
int		ft_strcmp(char *str1, char *str2);
size_t	length(char *str);
#endif

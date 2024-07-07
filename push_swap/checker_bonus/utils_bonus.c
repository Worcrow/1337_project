/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 07:47:27 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/04 08:18:01 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/push_swap_bonus.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	if (!lst)
		return (lst);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

size_t	stack_size(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}

static int	is_digit(char str, int *flag)
{
	if (str >= '0' && str <= '9')
		return (1);
	*flag = 1;
	return (0);
}

static void	is_valid_nbr(long nbr, int *flag)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		*flag = 1;
}

long	ft_atol(char *s, int *errno)
{
	long	result;
	int		sign;
	int		flag;

	initialize_var(&result, &sign, &flag);
	while (*s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s)
	{
		if (is_digit(*s, errno))
			result = result * 10 + (*s++ - '0');
		flag = 1;
		is_valid_nbr(result * sign, errno);
		if (*errno)
			return (0);
	}
	if (!flag)
		*errno = 1;
	return (result * sign);
}

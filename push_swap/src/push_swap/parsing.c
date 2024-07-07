/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:19:16 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/04 06:36:59 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

static int	*get_numbers(char **numbers, size_t size, int **numbers_int)
{
	size_t	i;
	int		errno;
	int		*numbers_list;

	numbers_list = (int *) malloc(size * sizeof(int));
	if (!*numbers)
		send_error("Error\n", 2);
	if (!numbers_list)
		(free_arg(numbers), send_error("Error\n", 2));
	i = 0;
	errno = 0;
	while (i < size)
	{
		numbers_list[i] = ft_atol(numbers[i], &errno);
		if (errno)
		{
			(free_arg(numbers), free(numbers_list));
			(free(*numbers_int), *numbers_int = NULL);
			send_error("Error\n", 3);
		}
		i++;
	}
	free_arg(numbers);
	return (numbers_list);
}

static void	copy_to(int *src, int *dest, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	merge(int **numbers, int *number_list, size_t *size, \
	size_t sub_size)
{
	int	*temp;
	int	flag;

	temp = (int *) malloc((*size + sub_size) * sizeof(int));
	flag = 0;
	if (*numbers)
	{
		copy_to(*numbers, temp, *size);
		flag = 1;
	}
	if (flag)
		copy_to(number_list, temp + *size, sub_size);
	else
		copy_to(number_list, temp, sub_size);
	*size += sub_size;
	free(*numbers);
	free(number_list);
	*numbers = temp;
}

int	*parse_arg(int argc, char **argv, size_t *size)
{
	char	**number_list;
	int		*numbers;
	int		*temp_nbrs;
	int		i;
	size_t	sub_size;

	numbers = NULL;
	i = 0;
	sub_size = 0;
	if (argc == 2)
	{
		number_list = ft_split(*(argv + 1), size);
		numbers = get_numbers(number_list, *size, &numbers);
	}
	else if (argc > 2)
	{
		while (++i < argc)
		{
			number_list = ft_split(argv[i], &sub_size);
			temp_nbrs = get_numbers(number_list, sub_size, &numbers);
			merge(&numbers, temp_nbrs, size, sub_size);
		}
	}
	return (numbers);
}

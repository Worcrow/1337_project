/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:39:09 by oel-asri          #+#    #+#             */
/*   Updated: 2024/05/23 01:49:54 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bzero(char *array)
{
	int	i;

	i = 0;
	while (i < 5)
		array[i++] = 0;
}

void	set_num_bytes(int bytes_received, int *num_bytes)
{
	if (bytes_received < 128)
		*num_bytes = 1;
	else if ((bytes_received & 224) == 192)
		*num_bytes = 2;
	else if ((bytes_received & 240) == 224)
		*num_bytes = 3;
	else if ((bytes_received & 248) == 240)
		*num_bytes = 4;
}

void	initialize_variables(t_utf8 *message)
{
	message->bytes_received = 0;
	message->byte_index = 0;
	message->bit_counter = 0;
	message->num_bytes = 1;
	ft_bzero(message->utf8_bytes);
}

void	print_message(char *message, int exit_status)
{
	int	i;

	i = 0;
	ft_printf("%s", message);
	if (exit_status != 0)
		exit(exit_status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:33:29 by oel-asri          #+#    #+#             */
/*   Updated: 2024/05/25 10:40:42 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include "../ft_printf/include/function_used.h"
# include <stdlib.h>

typedef struct minitalk
{
	char	utf8_bytes[5];
	int		bytes_received;
	int		byte_index;
	int		bit_counter;
	int		num_bytes;
}	t_utf8;

void	ft_bzero(char *array);
void	set_num_bytes(int bytes_received, int *num_bytes);
void	initialize_variables(t_utf8 *message);
void	send_sigusr1(void);
void	print_message(char *message, int exit_status);
#endif

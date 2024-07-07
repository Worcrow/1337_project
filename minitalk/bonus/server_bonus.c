/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:33:29 by oel-asri          #+#    #+#             */
/*   Updated: 2024/05/25 10:45:41 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_pid;

void	send_sigusr1(void)
{
	if (kill(g_pid, SIGUSR1) < 0)
	{
		ft_printf("Kill Failed To Send Back The signal\n");
		exit(-1);
	}
}

void	decode_message(int signum, siginfo_t *info, \
		void *context __attribute__ ((unused)))
{
	static t_utf8	message;

	if (info->si_pid != g_pid)
	{
		g_pid = info->si_pid;
		initialize_variables(&message);
	}
	if (signum == SIGUSR1)
		message.bytes_received |= (1 << message.bit_counter);
	if (++message.bit_counter == 8)
	{
		if (message.byte_index == 0)
			set_num_bytes(message.bytes_received, &message.num_bytes);
		message.utf8_bytes[message.byte_index++] = message.bytes_received;
		if (--message.num_bytes == 0)
		{
			message.utf8_bytes[++message.byte_index] = '\0';
			message.byte_index = 0;
			ft_printf("%s", message.utf8_bytes);
			ft_bzero(message.utf8_bytes);
		}
		message.bit_counter = 0;
		message.bytes_received = 0;
		send_sigusr1();
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = decode_message;
	ft_printf("%d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &action, 0);
		sigaction(SIGUSR2, &action, 0);
		pause();
	}
	return (0);
}

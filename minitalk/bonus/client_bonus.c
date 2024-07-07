/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:33:04 by oel-asri          #+#    #+#             */
/*   Updated: 2024/05/25 10:39:31 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_pid;

pid_t	get_pid(char *pid)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (pid[i] != '\0')
	{
		if (pid[i] >= '0' && pid[i] <= '9')
			result = result * 10 + (pid[i] - '0');
		else
			print_message("Invallid Pid. \
					Pid can't be negatif and have only numbers\n", 1);
		if (result >= 2147483648)
			print_message("Inavlid Pid.\n", 1);
		++i;
	}
	if (result == 0)
		print_message("Pid Can't Be Zero\n", 1);
	return ((pid_t) result);
}

void	receive_signal(int signum, siginfo_t *info, \
		void *context __attribute__ ((unused)))
{
	if (info->si_pid == g_pid && signum == SIGUSR1)
		ft_printf("Message Received\n");
}

void	send_message_to_server(char *message)
{
	int	i;
	int	j;
	int	kill_return;

	i = 0;
	while (message[i])
	{
		j = -1;
		while (++j < 8)
		{
			if (message[i] & (1 << j))
				kill_return = kill(g_pid, SIGUSR1);
			else
				kill_return = kill(g_pid, SIGUSR2);
			if (kill_return < 0)
				print_message("Kill Failed To Send The Signal\n", -1);
			usleep(1000);
		}
		++i;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	client_action;

	client_action.sa_flags = SA_SIGINFO;
	client_action.sa_sigaction = receive_signal;
	sigaction(SIGUSR1, &client_action, 0);
	if (argc == 3)
	{
		g_pid = get_pid(argv[1]);
		send_message_to_server(argv[2]);
	}
	else
		print_message("Usage: ./client <Pid_server> <message_to_send>\n", 1);
}

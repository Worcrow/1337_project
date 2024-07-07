/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:33:04 by oel-asri          #+#    #+#             */
/*   Updated: 2024/05/25 08:30:28 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "ft_printf/include/function_used.h"

void	print_message(char *message, int exit_status)
{
	int	i;

	i = 0;
	ft_printf("%s", message);
	if (exit_status != 0)
		exit(exit_status);
}

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

void	send_message_to_server(char *message, pid_t pid)
{
	int	i;
	int	j;
	int	kill_return;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			if (message[i] & (1 << j))
				kill_return = kill(pid, SIGUSR1);
			else
				kill_return = kill(pid, SIGUSR2);
			if (kill_return < 0)
				print_message("Kill Failed To Send The Signal\n", -1);
			++j;
			usleep(1000);
		}
		++i;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = get_pid(argv[1]);
		send_message_to_server(argv[2], pid);
	}
	else
		print_message("Usage: ./client <Pid_server> <message_to_send>\n", 1);
}

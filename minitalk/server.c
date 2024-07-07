/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:33:29 by oel-asri          #+#    #+#             */
/*   Updated: 2024/05/25 08:44:04 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/include/function_used.h"

pid_t	g_pid;

void	decode_message(int signum, siginfo_t *info, \
		void *context __attribute__ ((unused)))
{
	static int	bytes;
	static int	result;

	if (info->si_pid != g_pid)
	{
		bytes = 0;
		result = 0;
		g_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		result = result | (1 << bytes);
	if (++bytes == 8)
	{
		write(1, &result, 1);
		bytes = 0;
		result = 0;
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

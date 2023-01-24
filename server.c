/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:27:06 by mdouzi            #+#    #+#             */
/*   Updated: 2023/01/24 22:28:43 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_byte[9];

void	ft_power(char *p)
{
	int	x;
	int	crt;
	int	y;

	x = 7;
	crt = 0;
	y = 1;
	while (x >= 0)
	{
		if (p[x] == '1')
			crt = crt + y;
		y = y * 2;
		x--;
	}
	write(1, &crt, 1);
}

void	sig_handler(int sig, siginfo_t *dsisa, void *vv)
{
	static int	i;
	static int	pid;

	(void)vv;
	if (pid != dsisa->si_pid)
	{
		i = 0;
		g_byte[0] = '\0';
		pid = dsisa->si_pid;
	}
	if (sig == 30)
		g_byte[i] = '0';
	if (sig == 31)
		g_byte[i] = '1';
	i++;
	if (i == 8)
	{
		i = 0;
		g_byte[8] = '\0';
		ft_power(g_byte);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("%d\n", pid);
	while (1)
		pause();
	return (0);
}

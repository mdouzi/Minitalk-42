/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:30:06 by mdouzi            #+#    #+#             */
/*   Updated: 2023/01/30 14:53:35 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*to_binary(int i)
{
	int			a;
	static char	bin[9];

	a = 7;
	while (i != 0 && a >= 0)
	{
		bin[a] = (i % 2) + '0';
		i = i / 2;
		a--;
	}
	bin[8] = '\0';
	while (a >= 0)
	{
		bin[a] = '0';
		a--;
	}
	return (bin);
}

void	send_sig(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		if (str[i] == '1')
			kill(pid, SIGUSR2);
		i++;
		usleep(150);
	}
}

void	send_message(char *str, int pid)
{
	int		i;
	int		j;
	int		k;
	char	*bin;

	i = 0;
	k = 0;
	bin = (char *)malloc((sizeof(char) * ft_strlen(str) * 8) + 1);
	while (i < (int)ft_strlen(str))
	{
		j = 0;
		while (j < 8)
		{
			bin[k] = to_binary((unsigned char)str[i])[j];
			j++;
			k++;
		}
		i++;
	}
	bin[k] = '\0';
	j = 0;
	send_sig(bin, pid);
	send_sig("00000000", pid);
	free(bin);
}

void	sig_handler1(int sig, siginfo_t *dsisa, void *vv)
{
	(void)dsisa;
	(void)vv;
	if (sig == SIGUSR1)
	{
		ft_printf("message wsel\n");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	char				*str;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("something went wrong");
		exit(1);
	}
	sa.sa_sigaction = sig_handler1;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	if (pid == -1)
	{
		ft_printf("machi pid hadi");
		exit(1);
	}
	str = argv[2];
	send_message(str, pid);
	while (1)
		pause();
	return (0);
}

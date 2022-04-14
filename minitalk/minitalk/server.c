/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:00:13 by ylambark          #+#    #+#             */
/*   Updated: 2022/03/29 09:00:19 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	reset(int *curr_pid, int *cli_pid, int *i, char *byte)
{
	*cli_pid = *curr_pid;
	*byte = 0;
	*i = 0;
}

static void	handle(int sig, siginfo_t *info, void *p)
{
	static int	i;
	static char	k;
	static int	pid;
	static int	cli_pid;

	(void)p;
	if (!cli_pid)
		cli_pid = info->si_pid;
	pid = info->si_pid;
	if (pid != cli_pid)
		reset(&pid, &cli_pid, &i, &k);
	k = (k << 1) | (sig & 1);
	i++;
	if (i == 8)
	{
		ft_putchar(k);
		k = 0;
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr("THIS IS THE PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle;
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
	return (0);
}

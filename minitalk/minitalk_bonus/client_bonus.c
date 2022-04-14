/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:03:38 by ylambark          #+#    #+#             */
/*   Updated: 2022/03/30 08:37:17 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	end_msg(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr("✅✅✅ MESSAGE SENT ✅✅✅\n");
		exit(1);
	}
}

static void	hand(int sig)
{
	if (sig == SIGUSR2)
		usleep(200);
}

static void	send(int pid, char k)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (kill(pid, SIGUSR1 + ((k >> i) & 1)) == -1)
		{
			ft_putstr("❌❌❌ ERROR MESSAGE WAS NOT SENT ❌❌❌");
			exit (1);
		}
		i--;
		usleep(500);
	}
}

static void	affich(int i, int pid)
{
	if (i == 1)
		ft_putstr("⏳⏳⏳ SENDING MESSAGE PLEASE WAIT ⏳⏳⏳\n");
	if (pid <= 0)
	{
		ft_putstr("Invalid pid");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	signal(SIGUSR1, end_msg);
	signal(SIGUSR2, hand);
	if (ac != 3)
	{
		ft_putstr("invalid PID AND MESSAGE");
		return (0);
	}
	if (ac == 3)
	{
		affich(0, ft_atoi(av[1]));
		while (av[2][i])
		{
			send(ft_atoi(av[1]), av[2][i++]);
			affich(i, 1);
		}
		send(ft_atoi(av[1]), '\0');
	}
	return (0);
}

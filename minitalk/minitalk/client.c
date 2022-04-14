/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:00:32 by ylambark          #+#    #+#             */
/*   Updated: 2022/03/29 09:00:34 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char k)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR1 + ((k >> i) & 1));
		i--;
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		exit(1);
	if (ac == 3)
	{
		while (av[2][i])
			send(pid, av[2][i++]);
	}
	return (0);
}

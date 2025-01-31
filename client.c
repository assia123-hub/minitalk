/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:04:52 by aschalh           #+#    #+#             */
/*   Updated: 2025/01/31 20:55:17 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char character)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if ((character >> (7 - i)) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		write(1, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	i = 0;
	pid = atoi(av[1]);

	while (av[2][i])
	{
		send_signal(pid, av[2][i]);
		i++;
	}
	send_signal(pid, '\0');
	return (0);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:04:52 by aschalh           #+#    #+#             */
/*   Updated: 2025/02/03 21:19:06 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <limits.h>

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
void	send_signals(int pid, unsigned char character)
{
	int	i;

	i = 7;
	while (i >= 0) 
	{
		if (character & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		i--;
	}
}

int	main(int ac, char **av)
{
	int pid;
	int i;

	if (ac != 3) 
	{
		write(1, "error using: ./client PID \"message\"\n", 37);
		return (1);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid >= INT_MAX)
	{
		write(1, "PID makhdamch\n", 15);
		return (1);
	}

	while (av[2][i])
	{
		send_signals(pid, av[2][i]); 
		i++;
	}
	send_signals(pid, '\0');
	return (0);
}

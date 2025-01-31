/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:05:19 by aschalh           #+#    #+#             */
/*   Updated: 2025/01/31 23:59:20 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int				bit = 0;
	static unsigned char	character = 0;

	if (signum == SIGUSR1)
		character |= (1 << (7 - bit));
		else if (signum == SIGUSR2)
		character &= ~(1 << (7 - bit));

	bit++;
	if (bit == 8)
	{
		if (character == '\0')
		{
			write(1, "\n", 1);
		}
		else
		{
			write(1, &character, 1);
		}
		bit = 0;
		character = 0;
	}
}

int	main(void)
{
	write(1, "Server PID: ", 12);
	printf("%d\n", getpid());

	
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while (1)
		pause();
}




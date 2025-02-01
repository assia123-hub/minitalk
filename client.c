/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:04:52 by aschalh           #+#    #+#             */
/*   Updated: 2025/02/01 16:44:35 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    send_signal(int pid, unsigned char character)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if (character & (1 << i))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(500);
        i--;
    }
}

int    main(int ac, char **av)
{
    int    pid;
    int    i;

    if (ac != 3)
    {
        write(1, "Usage: ./client <PID> <message>\n", 31);
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
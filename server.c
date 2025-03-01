/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:05:19 by aschalh           #+#    #+#             */
/*   Updated: 2025/02/04 00:40:58 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void ft_putchar(char c)
{
    write(1, &c, 1);
}

static void    ft_putnbr(int n)
{
    if (n == -2147483648)
        write(1, "-2147483648", 11);
    else if (n >= 0 && n <= 9)
        ft_putchar(n + '0');
    else if (n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else if (n < 0)
    {
        write(1, "-", 1);
        ft_putnbr(-n);
    }
}

void    ft_handler(int signum)
{
    static char    character = 0;
    static int    bit = 0;

    if (signum == SIGUSR1) 
        character |= (1 << (7 - bit));
    bit++; 

    if (bit == 8) 
    {
        write(1, &character, 1);
        if (character == '\0')
            write(1, "\n", 1);
        character = 0;
        bit = 0;
    }
}

void    ft_signals(void) 
{
    signal(SIGUSR1, ft_handler);
    signal(SIGUSR2, ft_handler);
}

int    main(void)
{
    write(1, "PID: ", 6);
    ft_putnbr(getpid());
    write(1, "\n", 1); 

    ft_signals();

    while (1) 
        pause(); 
    return (0);
}

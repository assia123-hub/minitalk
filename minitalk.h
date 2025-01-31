/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:06:31 by aschalh           #+#    #+#             */
/*   Updated: 2025/01/31 20:55:01 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	send_signal(int pid, unsigned char character);
void	signal_handler(int signum);
void	handle_server(int signals);

#endif
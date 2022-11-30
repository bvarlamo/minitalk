/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:50:16 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/11/22 15:35:52 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"

char	g_x;

char	bi_to_dec(char *buff)
{
	int	dec;

	dec = (128 * buff[7]) + (64 * buff[6]) + (32 * buff[5]) + (16 * buff[4]) + (
			8 * buff[3]) + (4 * buff[2]) + (2 * buff[1]) + (1 * buff[0]);
	return (dec);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_x = 1;
	else if (sig == SIGUSR2)
		g_x = 0;
}

void	loop(void)
{
	char	buff[8];
	int		i;

	i = 0;
	g_x = 2;
	while (1 == 1)
	{
		if (g_x != 2)
		{
			buff[i] = g_x;
			g_x = 2;
			i++;
			if (i == 8)
			{
				ft_printf("%c", bi_to_dec(buff));
				i = 0;
			}
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID: %d\n", getpid());
	loop();
	return (0);
}

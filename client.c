/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:16:16 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/11/22 14:13:33 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

void	into_bi(int asc, int pid)
{
	int	remain;
	int	i;

	i = 0;
	while (i < 8)
	{
		remain = asc % 2;
		if (remain == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		asc /= 2;
		i++;
	}
}

void	into_asc(char *argv, char *argv1)
{
	unsigned long	i;
	int				asc;
	int				pid;

	i = 0;
	pid = ft_atoi((const char *)argv1);
	while (argv[i])
	{
		asc = (int) argv[i];
		into_bi(asc, pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 2;
	if (argc < 3)
		return (1);
	while (i < argc)
	{
		into_asc(argv[i], argv[1]);
		i++;
		if (argv[i] && i != 2)
			into_asc(" ", argv[1]);
	}
	into_asc("\n", argv[1]);
	return (0);
}

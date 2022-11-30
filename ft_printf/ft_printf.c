/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:50:48 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/10/17 10:23:15 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

int	into_hex(unsigned long int n, char str)
{
	char	hex_num[20];
	int		i;
	int		count;

	i = 0;
	if (n == 0 && i++ == 0)
		hex_num[0] = '0';
	while (n != 0)
	{
		count = n % 16;
		if (count < 10)
			hex_num[i++] = count + 48;
		else
			hex_num[i++] = count + 55;
		n = n / 16;
	}
	count = i;
	while (i > 0)
	{
		if (str == 'x')
			ft_putchar_fd(ft_tolower(hex_num[--i]), 1);
		else
			ft_putchar_fd(hex_num[--i], 1);
	}
	return (count);
}

int	percent(va_list list, char str)
{
	int					count;
	unsigned long int	p;

	count = 0;
	if (str == 's')
		count = ft_putstr_fd(va_arg(list, char *), 1);
	else if (str == 'i' || str == 'd')
		count = ft_putnbr_fd(va_arg(list, int), 1);
	else if (str == 'c')
		count = ft_putchar_fd(va_arg(list, int), 1);
	else if (str == '%')
		count = ft_putchar_fd('%', 1);
	else if (str == 'x' || str == 'X')
		count = into_hex(va_arg(list, unsigned int), str);
	else if (str == 'p')
	{
		p = (unsigned long int)va_arg(list, void *);
		write (1, "0", 1);
		write (1, "x", 1);
		count = (into_hex(p, 'x')) + 2;
	}
	else if (str == 'u')
		count = ft_putnbr_fd_unsigned(va_arg(list, unsigned int), 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	list;

	count = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += percent(list, (char)str[i + 1]);
			i = i + 2;
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(list);
	return (count);
}

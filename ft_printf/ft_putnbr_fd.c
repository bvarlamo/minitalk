/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:29:23 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/10/17 10:29:25 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	actual_putnbr(int n, int fd, int count)
{
	if (n >= 10)
	{
		count += actual_putnbr(n / 10, fd, count);
	}
	ft_putchar_fd((n % 10 + '0'), fd);
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		count = actual_putnbr(n, fd, count);
		count++;
		return (count);
	}
	count = actual_putnbr(n, fd, count);
	return (count);
}

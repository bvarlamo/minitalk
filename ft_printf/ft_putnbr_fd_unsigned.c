/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:31:45 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/10/17 10:29:27 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	putnbr(unsigned int n, int fd, unsigned int count)
{
	if (n >= 10)
		count += putnbr(n / 10, fd, count);
	ft_putchar_fd((n % 10 + '0'), fd);
	return (count);
}

unsigned int	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	unsigned int	count;

	count = 1;
	count = putnbr(n, fd, count);
	return (count);
}

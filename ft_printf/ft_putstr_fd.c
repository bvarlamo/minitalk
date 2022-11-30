/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:26:36 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/10/17 10:30:29 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	char	*s1;

	s1 = "(null)";
	if (!s)
	{
		write(fd, s1, 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

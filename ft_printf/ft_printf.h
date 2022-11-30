/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:23:40 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/10/15 13:57:51 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>

int					ft_printf(const char *str, ...);
int					ft_putchar_fd(char c, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *s);
unsigned int		ft_putnbr_fd_unsigned(unsigned int n, int fd);

#endif /* Ft_printf_h */
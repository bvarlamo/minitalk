# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 10:50:53 by bvarlamo          #+#    #+#              #
#    Updated: 2021/10/14 10:56:35 by bvarlamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MANDATORY=	ft_printf.c ft_putchar_fd.c ft_putnbr_fd_unsigned.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c \


NAME	=	libftprintf.a

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -c

AR	= 	ar rcs

MANDATORYO=	$(MANDATORY:.c=.o)

all :		$(NAME)

$(NAME) :	$(MANDATORYO)
	$(AR) $(NAME) $(MANDATORYO)

$(MANDATORYO) :	$(MANDATORY)
	$(CC) $(CFLAGS) $(MANDATORY)

clean :
	$(RM) $(MANDATORYO)

fclean :	clean
	$(RM) $(NAME)

re :		fclean all
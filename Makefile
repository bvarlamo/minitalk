# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 14:40:24 by bvarlamo          #+#    #+#              #
#    Updated: 2021/11/22 16:20:06 by bvarlamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER=server.c
SRC_CLIENT=client.c

CC=gcc
CFLAGS=-Wall -Werror -Wextra
RM=rm -f

SERVER=server
CLIENT=client

lib=./ft_printf

all: ${SERVER} ${CLIENT}

${CLIENT}: 
		${CC} ${CFLAGS} ${SRC_CLIENT} -o ${CLIENT}

${SERVER}:
		make -C ${lib}
		${CC} ${CFLAGS} ${SRC_SERVER} ./ft_printf/libftprintf.a -o ${SERVER}

clean :
	make clean -C ${lib}

fclean :	clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	make fclean -C ${lib}

re :		fclean all



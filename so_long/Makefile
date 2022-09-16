# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 12:25:22 by sokhacha          #+#    #+#              #
#    Updated: 2022/09/02 12:25:33 by sokhacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra

LINK = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LINK}

clean:
	${RM} ${OBJS}

fclean:clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

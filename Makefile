# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 16:51:34 by saazcon-          #+#    #+#              #
#    Updated: 2023/11/29 17:01:34 by saazcon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
SRCS	= cub3d.c utils.c ft_slipt.c ft_free.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address
RM		= rm -f
LIBX	= -framework OpenGL -framework AppKit -lmlx

${NAME}:	${OBJS}
			${CC} ${CFLAGS} $(LIBX) ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
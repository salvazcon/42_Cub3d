# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 16:51:34 by saazcon-          #+#    #+#              #
#    Updated: 2024/01/04 12:55:52 by saazcon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
SRCS	= cub3d.c ft_utils.c ft_slipt.c ft_free.c ft_file.c ft_break.c ft_check.c
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
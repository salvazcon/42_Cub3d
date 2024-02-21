# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 16:51:34 by saazcon-          #+#    #+#              #
#    Updated: 2024/02/21 13:06:12 by saazcon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

SRCS	= cub3d.c \
ft_parser_01.c \
ft_parser_02.c \
ft_parser_03.c \
ft_parser_04.c \
ft_parser_05.c \
ft_game_01.c\
ft_game_02.c\
ft_game_03.c\
ft_slipt.c \
ft_utils.c \
ft_utils2.c \
ft_free.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address

RM		= rm -f

LIBX	= -framework OpenGL -framework AppKit
MLX		= ./mlx

all:		make_mlx ${NAME}

make_mlx:
			make all -C $(MLX)

${NAME}:	${OBJS} $(MLX)/libmlx.a
			${CC} ${CFLAGS} ${OBJS} -I$(MLX) $(MLX)/libmlx.a $(LIBX) -o ${NAME}

clean:
			${RM} ${OBJS}
			make clean -C $(MLX)

fclean:		clean
			${RM} ${NAME}
			make clean -C $(MLX)

re:			fclean all

.PHONY:		all clean fclean re
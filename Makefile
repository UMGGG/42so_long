# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyjeon <jaeyjeon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 16:01:20 by jaeyjeon          #+#    #+#              #
#    Updated: 2022/06/16 18:13:00 by jaeyjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
ar			= ar rcs
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

MLX_DIR		= ./mlx/

SRCS		= lib/42Get_Next_line/get_next_line.c draw_map.c\
			lib/42Get_Next_line/get_next_line_utils.c set_param.c copy_map.c \
			check_map.c check_map_wall.c so_long.c exit_game.c get_key.c move.c

OBJS		=	$(SRCS:.c=.o)

%.o : %.c
		${CC} ${CFLAGS} -c -o $@ $<

$(NAME):	$(OBJS)
			make -C $(MLX_DIR)
			$(CC) -o $(NAME) $(OBJS) $(MLX_FLAGS)

all: $(NAME)

clean:
				make -C $(MLX_DIR) clean
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re: clean all

PHONY: all clean fclean re

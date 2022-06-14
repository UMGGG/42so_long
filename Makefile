# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 16:01:20 by jaeyjeon          #+#    #+#              #
#    Updated: 2022/06/15 02:04:56 by jaeyjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libsolong.a

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit
RM			= rm -rf

INCS_DIR	= ./inc/
SRCS_DIR	= ./srcs/
MLX_DIR		= ./mlx/

SRCS		= lib/42Get_Next_line/get_next_line.c draw_map.c\
			lib/42Get_Next_line/get_next_line_utils.c set_param.c copy_map.c \
			check_map.c check_map_wall.c so_long.c exit_game.c get_key.c move.c

OBJS		=	$(SRCS:.c=.o)

%.o : %.c
		${CC} ${CFLAGS} -c -o $@ $<

$(NAME):	$(OBJS)
				ar crs $(NAME) $(OBJS)

all: $(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re: clean all

PHONY: all clean fclean re

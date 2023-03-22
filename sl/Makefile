# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 18:53:50 by min-cho           #+#    #+#              #
#    Updated: 2022/10/11 21:18:19 by min-cho          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = so_long
GNL = gnl
SO_LONG = so_long
MLX = mlx
SO_LONG_OBJS = ${SO_LONG_SRC:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -Lmlx -lmlx -framework OpenGL -framework AppKit

SO_LONG_SRC = gnl/ft_split.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c\
		c_err.c \
		c_event.c \
		c_img.c \
		c_img2.c \
		c_map.c \
		c_move.c \
		main.c
 
SO_LONG_OBJS = ${SO_LONG_SRC:.c=.o}

all: $(MLX) $(NAME)

$(NAME): $(SO_LONG_OBJS)
	@ $(CC) $(CFLAGS) $(SO_LONG_OBJS) -o $@ $(LIB)

$(MLX):
	@ make -C mlx
	
clean:
	@ make clean -C mlx
	@ rm -rf $(SO_LONG_OBJS)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all

g :
	gcc -g -Lmlx -lmlx -framework OpenGL -framework AppKit *.c gnl/*.c

.PHONY: all clean fclean re
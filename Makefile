# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 18:53:50 by min-cho           #+#    #+#              #
#    Updated: 2023/03/14 00:53:39 by min-cho          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = cub
GNL = gnl
CUB = cub
MLX = mlx
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -Lmlx -lmlx -framework OpenGL -framework AppKit

CUB_SRC =	gnl/ft_split.c \
			gnl/get_next_line_utils.c \
			gnl/get_next_line.c\
			main.c


CUB_OBJS = ${CUB_SRC:.c=.o}

all: $(MLX) $(NAME)

$(NAME): $(CUB_OBJS)
	@ $(CC) $(CFLAGS) $(CUB_OBJS) -o $@ $(LIB)

$(MLX):
	@ make -C mlx
	
clean:
	@ make clean -C mlx
	@ rm -rf $(CUB_OBJS)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all

g :
	gcc -g -Lmlx -lmlx -framework OpenGL -framework AppKit *.c gnl/*.c

.PHONY: all clean fclean re
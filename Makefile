# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 18:53:50 by min-cho           #+#    #+#              #
#    Updated: 2023/04/02 15:46:04 by min-cho          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CUB = cub
MLX = mlx
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJS_DIR	= ./objs

SRCS =	gnl/ft_split.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c\
		utils/ft_strcmp.c \
		utils/ft_strlcat.c \
		utils/ft_bzero.c \
		utils/ft_atoi.c \
		utils/ft_strncmp.c \
		srcs/main.c \
		srcs/info.c \
		srcs/get.c \
		srcs/error.c \
		srcs/parsing.c \
		srcs/is.c \
		srcs/set.c \
		srcs/set2.c \
		srcs/start.c \
		srcs/test.c \
		srcs/move.c \
		srcs/turn.c \
		srcs/raycasting.c \
		srcs/raycasting2.c


OBJS := ${SRCS:%.c=${OBJS_DIR}/%.o}

all: $(MLX) $(NAME)

${OBJS_DIR}:
	@mkdir ${OBJS_DIR}
	@mkdir ${OBJS_DIR}/gnl
	@mkdir ${OBJS_DIR}/utils
	@mkdir ${OBJS_DIR}/srcs

$(MLX):
	@ make -C mlx

$(NAME): $(OBJS)
	@ $(CC) $(LIB) -o $(NAME) $(OBJS)
	
${OBJS_DIR}/%.o: %.c | ${OBJS_DIR}
	@${CC} ${CFLAGS} -g -c $< -o $@
	
clean:
	@ make clean -C mlx
	@ rm -rf $(OBJS_DIR)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all

n:
	@ norminette gnl/*.h
	@ norminette srcs/*.h
	@ norminette ${SRCS}

.PHONY: all clean fclean re n
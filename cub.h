/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:52:17 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/22 02:19:53 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h" //unistd, stdlib
# include <fcntl.h>
# include <stdio.h>


# define SIZE	64

# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2
# define KEY_ESC	53

typedef struct s_img
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**floor;
	char	**ceiling;
} t_img;

typedef struct s_info
{
	int		size;
	char	**map;
	t_img	img;
} t_info;

typedef struct s_game
{
	void	*mlx;	
	void	*win;
	int		x;
	int		y;
}	t_game;

//use libft
int		ft_strcmp(const char *str1, const char *str2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

//error.c
void	printErr(char *s1);

//parsing.c
void	parsing(int argc, char **argv, t_info *info);

//get.c
void	get_info(t_info *info, char **argv);

//info.c
int	is_xpm(char *tmp, t_info *info);

#endif
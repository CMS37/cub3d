/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:52:17 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/27 18:39:52 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h" //unistd, stdlib
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

# define SIZE	64

# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2
# define KEY_ESC	53
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124

# define WIDTH 640
# define HEIGHT 480
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

typedef struct s_img
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
} t_img;

typedef struct s_imgptr
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
	int		width;
	int		height;
} t_imgptr;

typedef struct s_info
{
	char	**map;
	char	**rgb;
	int		size;
	int		f_color;
	int		c_color;
	t_img	img;
} t_info;

typedef struct s_tex
{
	t_imgptr	no;
	t_imgptr	so;
	t_imgptr	we;
	t_imgptr	ea;
} t_tex;

typedef struct	s_vec
{
	double	x;
	double	y;
} t_vec;

typedef struct s_vec_int
{
	int	x;
	int	y;
}	t_vec_int;


typedef struct s_player
{
	int	x;
	int	y;
} t_player;

typedef struct s_game
{
	void		*mlx;	
	void		*win;
	char		**map;
	int			f_color;
	int			c_color;
	int			angle;
	t_vec		pos;	//플레이어의 위치 좌표
	t_vec		dir;	//백터 좌표
	t_vec		plane;	//fov시야각 좌표
	t_vec		ray;	//광선 방향 벡터
	t_tex		tex;
	int			buf[HEIGHT][WIDTH];
	t_imgptr	window_img;
}	t_game;

//use libft
int		ft_strcmp(const char *str1, const char *str2);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		white_space(char c);
int		ft_atoi(const char *nptr);

//error.c
void	print_err(char *s1);

//parsing.c
void	parsing(int argc, char **argv, t_info *info);

//get.c
void	get_info(t_info *info, char **argv);

//info.c
int		is_xpm(char *tmp, t_info *info);
char	*check_xpm_file(char *tmp);

//main.c
void	free_map(char **map);
void	free_info(t_info *info);

//start.c
void	start_game(t_info *info);
char	**copy_map(char **map, int size);

//set.c
void	set_img(char **patch, char *tmp);
void	set_game(t_game *g, t_info *info);

//test.c
int	test(t_game *g);

#endif
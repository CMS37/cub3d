/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:29:12 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/06 14:45:23 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h" //unistd, stdlib
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

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
}	t_img;

typedef struct s_imgptr
{
	void			*img;
	unsigned int	*addr;
	int				bpp;
	int				len;
	int				end;
	int				width;
	int				height;
}	t_imgptr;

typedef struct s_info
{
	char	**map;
	int		size;
	int		f_flag;
	int		f_color;
	int		c_flag;
	int		c_color;
	t_img	img;
}	t_info;

typedef struct s_tex
{
	t_imgptr	no;
	t_imgptr	so;
	t_imgptr	we;
	t_imgptr	ea;
}	t_tex;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_vec_int
{
	int	x;
	int	y;
}	t_vec_int;

typedef struct s_game
{
	void			*mlx;	
	void			*win;
	char			**map;
	int				f_color;
	int				c_color;
	int				angle;
	t_vec			pos;
	t_vec			dir;
	t_vec			plane;
	t_vec			ray;
	t_tex			tex;
	unsigned int	buf[HEIGHT][WIDTH];
	t_imgptr		window_img;
}	t_game;

typedef struct s_raycast_info
{
	t_vec_int	step;
	t_vec_int	map;
	double		perp_wall_dist;
	int			side;
	t_vec_int	texture;
}	t_ray;

//use libft
int		white_space(char c);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *str1, const char *str2);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

//error.c
void	print_err(char *s1);

//parsing.c
void	parsing(int argc, char **argv, t_info *info);

//get.c
void	get_info(t_info *info, char **argv);

//info.c
int		set_info(char *tmp, t_info *info);

//main.c
void	free_map(char **map);
void	free_info(t_info *info);

//start.c
void	start_game(t_info *info);
char	**copy_map(char **map, int size);

//set.c
void	set_img(char **patch, char *tmp);
void	set_game(t_game *g, t_info *info);

//set2.c
void	set_dir_plane(t_game *g);
void	draw_window(t_game *g);

//is.c
int		is_player(char c);
int		is_closed(t_game *g, int x, int y);
int		map_identi(char c);
int		check_map(char **map, int x, int y);

//move.c
void	move_front(t_game *g);
void	move_back(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);

//turn.c
void	turn_left(t_game *g);
void	turn_right(t_game *g);

//raycasting.c
void	raycasting(t_game *g);

//raycasting2.c
void	floor_ceil_to_buf(t_game *g);
int		get_side(t_game *g, t_ray *r, int x_cnt);
double	get_perp_wall_dist(t_game *g, t_ray r);

//raycasting3.c
void	set_step_side_dist(t_game *g, t_ray *r, t_vec *delta_dist, \
t_vec *side_dist);

#endif
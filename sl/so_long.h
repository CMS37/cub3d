/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:06:33 by min-cho           #+#    #+#             */
/*   Updated: 2022/10/17 17:16:08 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>

# define SIZE	64

# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2
# define KEY_ESC	53

typedef struct s_map
{
	int	x;
	int	y;
	int	player;
	int	exit;
	int	collect;
	int	wall;
	int	empty;
}	t_map;

typedef struct s_img
{
	void	*player;
	void	*floor;
	void	*wall;
	void	*gold;
	void	*exit;
	int		x;
	int		y;
}	t_img;

typedef struct s_map_set
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map2;
	char	**map;
	int		x;
	int		y;
	int		player_coin;
	int		move_count;
}	t_map_set;

char	**check_err(int argc, char **argv, t_map *map);
char	**make_map(int fd, t_map *map);
t_img	ft_convert_img(t_map_set *game);
void	ft_put_floor(t_map_set *game);
void	ft_put_obj(t_map_set *game, t_map map2, char **map);
int		ft_key_event(int keycode, t_map_set *game);
void	ft_put_player(t_map_set *game, int x, int y);
void	ft_put_wall(t_map_set *game, int x, int y);
void	ft_put_gold(t_map_set *game, int x, int y);
void	ft_put_exit(t_map_set *game, int x, int y);
void	update(t_map_set *game, int x, int y);
void	up(t_map_set *game);
void	down(t_map_set *game);
void	right(t_map_set *game);
void	left(t_map_set *game);
int		end_game(t_map_set *game);
int		check_wrong_word(char *str);
void	map_err(int i);
int		check_first_wall(char *str);
void	clear_map(t_map *map);
void	check_last_wall(char **str, t_map *map);
void	map_err(int i);
void	ft_putnbr(unsigned int n);

#endif
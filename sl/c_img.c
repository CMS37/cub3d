/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_img.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:18:21 by min-cho           #+#    #+#             */
/*   Updated: 2022/10/11 20:27:19 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_floor(t_map_set *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= game->map2.y)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor, \
								(x * SIZE), (y * SIZE));
		x++;
		if (x > game->map2.x)
		{
			if (y == game->map2.y)
				break ;
			y++;
			x = 0;
		}
	}
}

void	ft_put_obj(t_map_set *game, t_map map2, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y][x])
	{
		if (map[y][x] == 'P')
			ft_put_player(game, x, y);
		else if (map[y][x] == '1')
			ft_put_wall(game, x, y);
		else if (map[y][x] == 'C')
			ft_put_gold(game, x, y);
		else if (map[y][x] == 'E')
			ft_put_exit(game, x, y);
		x++;
		if (!map[y][x])
		{
			y++;
			x = 0;
			if (y == map2.y)
				break ;
		}
	}
}

t_img	ft_convert_img(t_map_set *game)
{
	int		i;

	i = SIZE;
	game->img.player = mlx_xpm_file_to_image(game->mlx, \
												"./img/player1.xpm", &i, &i);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, \
												"./img/floor.xpm", &i, &i);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &i, &i);
	game->img.gold = mlx_xpm_file_to_image(game->mlx, "./img/gold.xpm", &i, &i);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &i, &i);
	return (game->img);
}

void	update(t_map_set *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor, \
							game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor, x, y);
	mlx_put_image_to_window(game->mlx, game->win, game->img.player, x, y);
}

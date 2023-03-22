/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_img2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:13:00 by min-cho           #+#    #+#             */
/*   Updated: 2022/10/11 20:28:46 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_map_set *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.player, \
		(x * SIZE), (y * SIZE));
	game->x = (x * SIZE);
	game->y = (y * SIZE);
}

void	ft_put_wall(t_map_set *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.wall, \
		(x * SIZE), (y * SIZE));
}

void	ft_put_gold(t_map_set *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.gold, \
		(x * SIZE), (y * SIZE));
}

void	ft_put_exit(t_map_set *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.exit, \
		(x * SIZE), (y * SIZE));
}

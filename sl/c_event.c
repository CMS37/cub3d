/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:54:17 by min-cho           #+#    #+#             */
/*   Updated: 2022/10/12 21:12:43 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map_set *game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
}

int	end_game(t_map_set *game)
{
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	ft_key_event(int keycode, t_map_set *game)
{
	if (keycode == KEY_ESC)
		end_game(game);
	if (keycode == KEY_A)
		left(game);
	if (keycode == KEY_D)
		right(game);
	if (keycode == KEY_W)
		up(game);
	if (keycode == KEY_S)
		down(game);
	return (0);
}

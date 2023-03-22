/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:09:24 by min-cho           #+#    #+#             */
/*   Updated: 2022/10/17 17:11:14 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_check(t_map_set *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	else if (game->map[y][x] == 'C')
	{
		game->player_coin++;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->map2.collect != game->player_coin)
			return (0);
		end_game(game);
	}
	return (1);
}

void	up(t_map_set *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y - SIZE;
	if (move_check(game, (x / SIZE), (y / SIZE)))
	{
		update(game, x, y);
		ft_putnbr(++game->move_count);
		write (1, "\n", 1);
		game->x = x;
		game->y = y;
	}
}

void	down(t_map_set *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y + SIZE;
	if (move_check(game, (x / SIZE), (y / SIZE)))
	{
		update(game, x, y);
		ft_putnbr(++game->move_count);
		write (1, "\n", 1);
		game->x = x;
		game->y = y;
	}
}

void	right(t_map_set *game)
{
	int	x;
	int	y;

	x = game->x + SIZE;
	y = game->y;
	if (move_check(game, (x / SIZE), (y / SIZE)))
	{
		update(game, x, y);
		ft_putnbr(++game->move_count);
		write (1, "\n", 1);
		game->x = x;
		game->y = y;
	}
}

void	left(t_map_set *game)
{
	int	x;
	int	y;

	x = game->x - SIZE;
	y = game->y;
	if (move_check(game, (x / SIZE), (y / SIZE)))
	{
		update(game, x, y);
		ft_putnbr(++game->move_count);
		write (1, "\n", 1);
		game->x = x;
		game->y = y;
	}
}

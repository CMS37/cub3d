/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:31:31 by min-cho           #+#    #+#             */
/*   Updated: 2022/10/17 17:11:30 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(unsigned int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	write (1, &"0123456789"[n % 10], 1);
}

void	clear_game(t_map_set *game)
{
	game->x = 0;
	game->y = 0;
	game->player_coin = 0;
	game->move_count = 0;
}

void	clear_map(t_map *map)
{
	map->collect = 0;
	map->empty = 0;
	map->exit = 0;
	map->player = 0;
	map->wall = 0;
	map->x = 0;
	map->y = 0;
}

void	start_game(char **map, t_map map2)
{
	t_map_set	game;

	clear_game(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map2.x * SIZE, \
								map2.y * SIZE, "so_long");
	game.img = ft_convert_img(&game);
	game.map2 = map2;
	ft_put_floor(&game);
	ft_put_obj(&game, map2, map);
	game.map = map;
	mlx_hook(game.win, 17, 0, end_game, &game);
	mlx_hook(game.win, 2, 0, ft_key_event, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_map	map2;

	map = check_err(argc, argv, &map2);
	start_game(map, map2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:13:36 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/22 02:33:38 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	end_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
	return (0);
}

static int key_event(int input, t_game *g)
{
	if (input == KEY_ESC)
		end_game(g);
	if (input == KEY_A)
		;
	if (input == KEY_D)
		;
	if (input == KEY_W)
		;
	if (input == KEY_S)
		;
}

void	start_game(t_info *info)
{
	t_game g;
	
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 720, 720, "Cub3d");
	// g = info < make 
	//free(info) < make
	mlx_hook(g.win, 17, 0, end_game, &g);
	mlx_hook(g.win, 2, 0, key_event, &g);
	mlx_loop(g.mlx);
}
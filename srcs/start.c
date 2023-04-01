/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:13:36 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/30 14:01:35 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

static int	end_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
	return (0);
}

static int	key_event(int input, t_game *g)
{
	if (input == KEY_ESC)
		end_game(g);
	if (input == KEY_W)
	{
		if (g->map[(int)g->pos.y][(int)(g->pos.x + g->dir.x * 0.05)] == '0')
			g->pos.x += g->dir.x * 0.05;
		if (g->map[(int)(g->pos.y + g->dir.y * 0.05)][(int)(g->pos.x)] == '0')
			g->pos.y += g->dir.y * 0.05;
	}
	if (input == KEY_S)
	{
		if (g->map[(int)(g->pos.y)][(int)(g->pos.x - g->dir.x * 0.05)] == '0')
			g->pos.x -= g->dir.x * 0.05;
		if (g->map[(int)(g->pos.y - g->dir.y * 0.05)][(int)(g->pos.x)] == '0')
			g->pos.y -= g->dir.y * 0.05;
	}
	if (input == KEY_D)
	{
		if (g->map[(int)(g->pos.y - g->dir.x * 0.05)][(int)(g->pos.x)] == '0')
			g->pos.y -= g->dir.x * 0.05;
		if (g->map[(int)(g->pos.y)][(int)(g->pos.x - g->dir.x * 0.05)] == '0')
			g->pos.x += g->dir.y * 0.05;
	}
	if (input == KEY_A)
	{
		if (g->map[(int)(g->pos.y + g->dir.x * 0.05)][(int)(g->pos.x)] == '0')
			g->pos.y += g->dir.x * 0.05;
		if (g->map[(int)(g->pos.y)][(int)(g->pos.x - g->dir.x * 0.05)] == '0')
			g->pos.x -= g->dir.y * 0.05;
	}
	if (input == KEY_ARROW_LEFT)
	{
		double oldDirX = g->dir.x;
		g->dir.x = g->dir.x * cos(0.05) - g->dir.y * sin(0.05);
		g->dir.y = oldDirX * sin(0.05) + g->dir.y * cos(0.05);
		double oldPlaneX = g->plane.x;
		g->plane.x = g->plane.x * cos(0.05) - g->plane.y * sin(0.05);
		g->plane.y = oldPlaneX * sin(0.05) + g->plane.y * cos(0.05);
	}
	if (input == KEY_ARROW_RIGHT)
	{
		double oldDirX = g->dir.x;
		g->dir.x = g->dir.x * cos(-0.05) - g->dir.y * sin(-0.05);
		g->dir.y = oldDirX * sin(-0.05) + g->dir.y * cos(-0.05);
		double oldPlaneX = g->plane.x;
		g->plane.x = g->plane.x * cos(-0.05) - g->plane.y * sin(-0.05);
		g->plane.y = oldPlaneX * sin(-0.05) + g->plane.y * cos(-0.05);
	}
	return (0);
}

char	**copy_map(char **map, int size)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * (size - 5));
	if (!tmp)
		return (NULL);
	i = 0;
	while (map[i + 6])
	{
		tmp[i] = ft_strdup(map[i + 6]);
		if (!tmp[i])
		{
			free_map(tmp);
			return (NULL);
		}
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	start_game(t_info *info)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, WIDTH, HEIGHT, "Cub3D");
	set_game(&g, info);
	free_info(info);
	g.window_img.img = mlx_new_image(g.mlx, WIDTH, WIDTH);
	g.window_img.addr = (unsigned int *)mlx_get_data_addr(g.window_img.img, \
					&g.window_img.bpp, &g.window_img.len, &g.window_img.end);
	mlx_loop_hook(g.mlx, &test, &g);
	mlx_hook(g.win, 17, 0, end_game, &g);
	mlx_hook(g.win, 2, 0, key_event, &g);
	mlx_loop(g.mlx);
}

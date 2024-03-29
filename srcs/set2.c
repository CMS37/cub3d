/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:51:27 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/06 14:44:57 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_dir_plane(t_game *g)
{
	if (g->map[(int)g->pos.y][(int)g->pos.x] == 'W')
	{
		g->dir = (t_vec){-1.0, 0.0};
		g->plane = (t_vec){0.0, -0.66};
	}
	else if (g->map[(int)g->pos.y][(int)g->pos.x] == 'E')
	{
		g->dir = (t_vec){1.0, 0.0};
		g->plane = (t_vec){0.0, 0.66};
	}
	else if (g->map[(int)g->pos.y][(int)g->pos.x] == 'N')
	{
		g->dir = (t_vec){0.0, -1.0};
		g->plane = (t_vec){0.66, 0.0};
	}
	else if (g->map[(int)g->pos.y][(int)g->pos.x] == 'S')
	{
		g->dir = (t_vec){0.0, 1.0};
		g->plane = (t_vec){-0.66, 0.0};
	}
}

void	draw_window(t_game *g)
{
	int	y_cnt;
	int	x_cnt;

	y_cnt = 0;
	while (y_cnt < HEIGHT)
	{
		x_cnt = 0;
		while (x_cnt < WIDTH)
		{
			g->window_img.addr[y_cnt * WIDTH + x_cnt] = g->buf[y_cnt][x_cnt];
			x_cnt++;
		}
		y_cnt++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->window_img.img, 0, 0);
}

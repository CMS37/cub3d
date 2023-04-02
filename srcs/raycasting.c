/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:48:01 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/02 17:29:08 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static double	get_wall_x(t_game *g, int side, double perp_wall_dist)
{
	double	ret;

	if (side == 0)
		ret = g->pos.y + perp_wall_dist * g->ray.y;
	else
		ret = g->pos.x + perp_wall_dist * g->ray.x;
	ret -= floor(ret);
	return (ret);
}

static int	get_texture_x(t_game *g, double wall_x, int side)
{
	int	ret;

	ret = (int)(wall_x * (double)IMG_WIDTH);
	if (side == 0 && g->ray.x > 0)
		ret = IMG_WIDTH - ret - 1;
	if (side == 1 && g->ray.y < 0)
		ret = IMG_WIDTH - ret - 1;
	return (ret);
}

static void	texture_to_buf(t_game *g, t_vec_int texture, int line_hight, \
t_vec_int draw_start_end, int side, int x_cnt)
{
	double	tex_step;
	double	tex_pos;
	int		y_cnt;
	int		color;

	tex_step = 1.0 * IMG_HEIGHT / line_hight;
	tex_pos = (draw_start_end.x - HEIGHT / 2 + line_hight / 2) * tex_step;
	y_cnt = draw_start_end.x;
	while (y_cnt < draw_start_end.y)
	{
		texture.y = (int)tex_pos & (IMG_HEIGHT - 1);
		tex_pos += tex_step;
		if (side == 0)
		{
			if (g->ray.x > 0)
				color = ((int *)(g->tex.ea.addr))[IMG_HEIGHT * texture.y + (IMG_WIDTH -  texture.x)];
			else
				color = ((int *)(g->tex.we.addr))[IMG_HEIGHT * texture.y + (IMG_WIDTH -  texture.x)];
		}
		else
		{
			if (g->ray.y > 0)
				color = ((int *)(g->tex.so.addr))[IMG_HEIGHT * texture.y + (IMG_WIDTH -  texture.x)];
			else
				color = ((int *)(g->tex.no.addr))[IMG_HEIGHT * texture.y + (IMG_WIDTH -  texture.x)];
		}
		g->buf[y_cnt][x_cnt] = color;
		y_cnt++;
	}
}

void	raycasting(t_game *g)
{
	int			x_cnt;
	t_vec_int	map;
	t_vec_int	step;
	double		perp_wall_dist;
	int			side;
	t_vec_int	draw_start_end;
	t_vec_int	texture;

	floor_ceil_to_buf(g);
	x_cnt = 0;
	while (x_cnt < WIDTH)
	{
		side = get_side(g, &step, &map, x_cnt);
		perp_wall_dist = get_perp_wall_dist(g, map, step, side);
		draw_start_end.x = -((int)(HEIGHT / perp_wall_dist)) / 2 + HEIGHT / 2;
		if (draw_start_end.x < 0)
			draw_start_end.x = 0;
		draw_start_end.y = ((int)(HEIGHT / perp_wall_dist)) / 2 + HEIGHT / 2;
		if (draw_start_end.y >= HEIGHT)
			draw_start_end.y = HEIGHT - 1;
		texture.x = get_texture_x(g, get_wall_x(g, side, perp_wall_dist), side);
		texture_to_buf(g, texture, ((int)(HEIGHT / perp_wall_dist)), draw_start_end, side, x_cnt);
		x_cnt++;
	}
}

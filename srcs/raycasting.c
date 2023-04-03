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

static double	get_wall_x(t_game *g, t_ray r)
{
	double	ret;

	if (r.side == 0)
		ret = g->pos.y + r.perp_wall_dist * g->ray.y;
	else
		ret = g->pos.x + r.perp_wall_dist * g->ray.x;
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

static void	texture_to_buf(t_game *g, t_ray r, int x, int y)
{
	int ea_color;
	int we_color;
	int so_color;
	int no_color;

	ea_color = ((int *)(g->tex.ea.addr))[IMG_HEIGHT * r.texture.y + (IMG_WIDTH - r.texture.x)];
	we_color = ((int *)(g->tex.we.addr))[IMG_HEIGHT * r.texture.y + (IMG_WIDTH - r.texture.x)];
	so_color = ((int *)(g->tex.so.addr))[IMG_HEIGHT * r.texture.y + (IMG_WIDTH - r.texture.x)];
	no_color = ((int *)(g->tex.no.addr))[IMG_HEIGHT * r.texture.y + (IMG_WIDTH - r.texture.x)];
	if (r.side == 0)
	{
		if (g->ray.x > 0)
			g->buf[y][x] = ea_color;
		else
			g->buf[y][x] = we_color;
	}
	else
	{
		if (g->ray.y > 0)
			g->buf[y][x] = so_color;
		else
			g->buf[y][x] = no_color;
	}
}

static void	wall_to_buf(t_game *g, t_ray r, \
t_vec_int draw_start_end, int x_cnt)
{
	double	tex_step;
	double	tex_pos;
	int		y_cnt;
	int		line_hight;

	line_hight = ((int)(HEIGHT / r.perp_wall_dist));
	tex_step = 1.0 * IMG_HEIGHT / line_hight;
	tex_pos = (draw_start_end.x - HEIGHT / 2 + line_hight / 2) * tex_step;
	y_cnt = draw_start_end.x;
	while (y_cnt < draw_start_end.y)
	{
		r.texture.y = (int)tex_pos & (IMG_HEIGHT - 1);
		tex_pos += tex_step;
		texture_to_buf(g, r, x_cnt, y_cnt);
		// if (r.side == 0)
		// {
		// 	if (g->ray.x > 0)
		// 		g->buf[y_cnt][x_cnt] = ((int *)(g->tex.ea.addr))[IMG_HEIGHT * r.texture.y + (IMG_WIDTH -  r.texture.x)];
		// 	else
		// 		g->buf[y_cnt][x_cnt] = ((int *)(g->tex.we.addr))[IMG_HEIGHT * r.texture.y + (IMG_WIDTH -  r.texture.x)];
		// }
		// else
		// {
		// 	if (g->ray.y > 0)
		// 		g->buf[y_cnt][x_cnt] = ((int *)(g->tex.so.addr))[IMG_HEIGHT * r.texture.y + (IMG_WIDTH -  r.texture.x)];
		// 	else
		// 		g->buf[y_cnt][x_cnt] = ((int *)(g->tex.no.addr))[IMG_HEIGHT * r.texture.y + (IMG_WIDTH -  r.texture.x)];
		// }
		y_cnt++;
	}
}

void	raycasting(t_game *g)
{
	int			x_cnt;
	t_ray		r;
	// t_vec_int	map;
	// t_vec_int	step;
	// double		perp_wall_dist;
	// int			side;
	t_vec_int	draw_start_end;
	// t_vec_int	texture;

	floor_ceil_to_buf(g);
	x_cnt = 0;
	while (x_cnt < WIDTH)
	{
		r.side = get_side(g, &r, x_cnt);
		r.perp_wall_dist = get_perp_wall_dist(g, r);
		draw_start_end.x = -((int)(HEIGHT / perp_wall_dist)) / 2 + HEIGHT / 2;
		if (draw_start_end.x < 0)
			draw_start_end.x = 0;
		draw_start_end.y = ((int)(HEIGHT / perp_wall_dist)) / 2 + HEIGHT / 2;
		if (draw_start_end.y >= HEIGHT)
			draw_start_end.y = HEIGHT - 1;
		r.texture.x = get_texture_x(g, get_wall_x(g, r), r.side);
		wall_to_buf(g, r, draw_start_end, x_cnt);
		x_cnt++;
	}
}

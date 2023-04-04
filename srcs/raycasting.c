/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:48:01 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/04 15:10:18 by min-cho          ###   ########.fr       */
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
	int	*e_c_p;
	int	*w_c_p;
	int	*s_c_p;
	int	*n_c_p;
	int	location;

	e_c_p = ((int *)(g->tex.ea.addr));
	w_c_p = ((int *)(g->tex.we.addr));
	s_c_p = ((int *)(g->tex.so.addr));
	n_c_p = ((int *)(g->tex.no.addr));
	location = IMG_HEIGHT * r.texture.y + (IMG_WIDTH - r.texture.x);
	if (r.side == 0)
	{
		if (g->ray.x > 0)
			g->buf[y][x] = e_c_p[location];
		else
			g->buf[y][x] = w_c_p[location];
	}
	else
	{
		if (g->ray.y > 0)
			g->buf[y][x] = s_c_p[location];
		else
			g->buf[y][x] = n_c_p[location];
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
		y_cnt++;
	}
}

void	raycasting(t_game *g)
{
	int			x_cnt;
	t_ray		r;
	t_vec_int	draw_start_end;

	floor_ceil_to_buf(g);
	x_cnt = 0;
	while (x_cnt < WIDTH)
	{
		r.side = get_side(g, &r, x_cnt);
		r.perp_wall_dist = get_perp_wall_dist(g, r);
		draw_start_end.x = -((int)(HEIGHT / r.perp_wall_dist)) / 2 + HEIGHT / 2;
		if (draw_start_end.x < 0)
			draw_start_end.x = 0;
		draw_start_end.y = ((int)(HEIGHT / r.perp_wall_dist)) / 2 + HEIGHT / 2;
		if (draw_start_end.y >= HEIGHT)
			draw_start_end.y = HEIGHT - 1;
		r.texture.x = get_texture_x(g, get_wall_x(g, r), r.side);
		wall_to_buf(g, r, draw_start_end, x_cnt);
		x_cnt++;
	}
}

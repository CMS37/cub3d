/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:48:04 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/02 17:06:32 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	floor_ceil_to_buf(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			g->buf[y][x] = g->c_color;
			g->buf[HEIGHT - y - 1][x] = g->f_color;
			x++;
		}
		y++;
	}
}

static void	init_get_side(t_game *g, t_vec_int *map, t_vec *delta_dist)
{
	map->x = (int)g->pos.x;
	map->y = (int)g->pos.y;
	delta_dist->x = fabs(1 / g->ray.x);
	delta_dist->y = fabs(1 / g->ray.y);
	return ;
}

static int	get_hit(t_game *g, t_ray *r, \
t_vec side_dist, t_vec delta_dist)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			r->map.x += r->step.x;
			side = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			r->map.y += r->step.y;
			side = 1;
		}
		if (g->map[r->map.y][r->map.x] > '0')
			hit = 1;
	}
	return (side);
}

int	get_side(t_game *g, t_ray *r, int x_cnt)
{
	t_vec		delta_dist;
	t_vec		side_dist;

	g->ray.x = g->dir.x + g->plane.x * (2 * x_cnt / (double)WIDTH - 1);
	g->ray.y = g->dir.y + g->plane.y * (2 * x_cnt / (double)WIDTH - 1);
	init_get_side(g, &(r->map), &delta_dist);
	if (g->ray.x < 0)
	{
		r->step.x = -1;
		side_dist.x = (g->pos.x - r->map.x) * delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		side_dist.x = (r->map.x + 1.0 - g->pos.x) * delta_dist.x;
	}
	if (g->ray.y < 0)
	{
		r->step.y = -1;
		side_dist.y = (g->pos.y - r->map.y) * delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		side_dist.y = (r->map.y + 1.0 - g->pos.y) * delta_dist.y;
	}
	return (get_hit(g, r, side_dist, delta_dist));
}

double	get_perp_wall_dist(t_game *g, t_ray r)
{
	double	ret;

	if (side == 0)
		ret = (r.map.x - g->pos.x + (1 - r.step.x) / 2) / g->ray.x;
	else
		ret = (r.map.y - g->pos.y + (1 - r.step.y) / 2) / g->ray.y;
	return (ret);
}

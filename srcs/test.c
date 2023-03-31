/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:40:18 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/30 17:51:31 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	floor_ceil_to_buf(t_game *g)
{
	int x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			g->buf[y][x] = g->f_color;
			g->buf[HEIGHT - y - 1][x] = g->c_color;
			x++;
		}
		y++;
	}
}

void	init_get_side(t_game *g, t_vec_int *map, t_vec *delta_dist)
{
	map->x = (int)g->pos.x;
	map->y = (int)g->pos.y;
	delta_dist->x = fabs(1 / g->ray.x);
	delta_dist->y = fabs(1 / g->ray.y);
	return ;
}

int	get_hit(t_game *g, t_vec_int map, t_vec_int step, t_vec side_dist, t_vec delta_dist)
{
	int hit;
	int side;

	hit = 0;	
	while (hit == 0)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			map.x += step.x;
			side = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			map.y += step.y;
			side = 1;
		}
		if (g->map[map.y][map.x] > '0')
			hit = 1;
	}
	return (side);
}

int get_side(t_game *g, t_vec_int *step)
{
	t_vec_int	map;
	t_vec		delta_dist;

	g->ray.x = g->dir.x + g->plane.x * (2 * x_cnt / (double)WIDTH - 1);
	g->ray.y = g->dir.y + g->plane.y * (2 * x_cnt / (double)WIDTH - 1);
	init_get_side(&map, &delta_dist);
	// map.x = (int)g->pos.x;
	// map.y = (int)g->pos.y;
	// delta_dist.x = fabs(1 / g->ray.x);
	// delta_dist.y = fabs(1 / g->ray.y);
	if (g->ray.x < 0)
	{
		step->x = -1;
		side_dist.x = (g->pos.x - map.x) * delta_dist.x;
	}
	else
	{
		step->x = 1;
		side_dist.x = (map.x + 1.0 - g->pos.x) * delta_dist.x;
	}
	if (g->ray.y < 0)
	{
		step->y = -1;
		side_dist.y = (g->pos.y - map.y) * delta_dist.y;
	}
	else
	{
		step->y = 1;
		side_dist.y = (map.y + 1.0 - g->pos.y) * delta_dist.y;
	}
	return (get_hit(g, map, *step, side_dist, delta_dist));
}

double get_perp_wall_dist(t_game *g, t_vec_int map, t_vec_int step, int side)
{
	double ret;

	if (side == 0)
		ret = (map.x - g->pos.x + (1 - step.x) / 2) / g->ray.x;
	else
		ret = (map.y - g->pos.y + (1 - step.y) / 2) / g->ray.y;
	return (ret);
}

double	get_wall_x(t_game *g; int side, double perp_wall_dist)
{
	double	ret;

	if (side == 0)
		ret = g->pos.y + perp_wall_dist * g->ray.y;
	else
		ret = g->pos.x + perp_wall_dist * g->ray.x;
	ret -= floor(ret);
	return (ret);
}

int	get_texture_x(t_game *g, double wall_x, int side)
{
	int ret;

	ret = (int)(wall_x * (double)IMG_WIDTH);
	if (side == 0 && g->ray.x > 0)
		ret = IMG_WIDTH - ret - 1;
	if (side == 1 && g->ray.y < 0)
		ret = IMG_WIDTH - ret - 1;
	return (ret);
}

void	texture_to_buf(t_game *g, t_vec_int texture, int line_hight, t_vec_int draw_start_end, int side)
{
	double	tex_step;
	double 	tex_pos;
	int		y_cnt;

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
				g->buf[y_cnt][x_cnt] = ((int *)(g->tex.we.addr))[IMG_HEIGHT * texture.y + texture.x];
			else
				g->buf[y_cnt][x_cnt] = ((int *)(g->tex.ea.addr))[IMG_HEIGHT * texture.y + texture.x];
		}
		else
		{
			if (g->ray.y > 0)
				g->buf[y_cnt][x_cnt] = ((int *)(g->tex.so.addr))[IMG_HEIGHT * texture.y + texture.x];
			else
				g->buf[y_cnt][x_cnt] = ((int *)(g->tex.no.addr))[IMG_HEIGHT * texture.y + texture.x];
		}
		y_cnt++;
	}
}

void	raycasting(t_game *g)
{
	int			x_cnt;
	// t_vec_int	map;
	// t_vec		delta_dist;
	// t_vec		side_dist;
	t_vec_int	step;
	double		perp_wall_dist;
	// int 		hit;
	int			side;
	// int			line_hight;
	t_vec_int	draw_start_end;
	t_vec_int	texture;
	double		wall_x;
	// double		tex_step;
	// double 		tex_pos;
	// int			y_cnt;
	
	floor_ceil_to_buf(g);
	x_cnt = 0;
	while (x_cnt < WIDTH)
	{
		// g->ray.x = g->dir.x + g->plane.x * (2 * x_cnt / (double)WIDTH - 1);
		// g->ray.y = g->dir.y + g->plane.y * (2 * x_cnt / (double)WIDTH - 1);
		// map.x = (int)g->pos.x;
		// map.y = (int)g->pos.y;
		// delta_dist.x = fabs(1 / g->ray.x);
		// delta_dist.y = fabs(1 / g->ray.y);

		// if (g->ray.x < 0)
		// {
		// 	step.x = -1;
		// 	side_dist.x = (g->pos.x - map.x) * delta_dist.x;
		// }
		// else
		// {
		// 	step.x = 1;
		// 	side_dist.x = (map.x + 1.0 - g->pos.x) * delta_dist.x;
		// }
		// if (g->ray.y < 0)
		// {
		// 	step.y = -1;
		// 	side_dist.y = (g->pos.y - map.y) * delta_dist.y;
		// }
		// else
		// {
		// 	step.y = 1;
		// 	side_dist.y = (map.y + 1.0 - g->pos.y) * delta_dist.y;
		// }

		side = get_side(g, &step);
		// hit = 0;
		// while (hit == 0)
		// {
		// 	if (side_dist.x < side_dist.y)
		// 	{
		// 		side_dist.x += delta_dist.x;
		// 		map.x += step.x;
		// 		side = 0;
		// 	}
		// 	else
		// 	{
		// 		side_dist.y += delta_dist.y;
		// 		map.y += step.y;
		// 		side = 1;
		// 	}
		// 	if (g->map[map.y][map.x] > '0')
		// 		hit = 1;
		// }

		perp_wall_dist = get_perp_wall_dist(g, map, step, side);
		// if (side == 0)
		// 	perp_wall_dist = (map.x - g->pos.x + (1 - step.x) / 2) / g->ray.x;
		// else
		// 	perp_wall_dist = (map.y - g->pos.y + (1 - step.y) / 2) / g->ray.y;

		// line_hight = (int)(HEIGHT / perp_wall_dist);

		draw_start_end.x = -((int)(HEIGHT / perp_wall_dist)) / 2 + HEIGHT / 2;
		if (draw_start_end.x < 0)
			draw_start_end.x = 0;
		draw_start_end.y = ((int)(HEIGHT / perp_wall_dist)) / 2 + HEIGHT / 2;
		if (draw_start_end.y >= HEIGHT)
			draw_start_end.y = HEIGHT - 1;

		wall_x = get_wall_x(g, side, perp_wall_dist);
		// if (side == 0)
		// 	wall_x = g->pos.y + perp_wall_dist * g->ray.y;
		// else
		// 	wall_x = g->pos.x + perp_wall_dist * g->ray.x;
		// wall_x -= floor(wall_x);

		texture.x = get_texture_x(g, wall_x, side); // texture.x = get_texture_x(g, get_wall_x(g, side, perp_wall_dist), side);
		// texture.x = (int)(wall_x * (double)IMG_WIDTH);
		// if (side == 0 && g->ray.x > 0)
		// 	texture.x = IMG_WIDTH - texture.x - 1;
		// if (side == 1 && g->ray.y < 0)
		// 	texture.x = IMG_WIDTH - texture.x - 1;

		texture_to_buf(g, texture, ((int)(HEIGHT / perp_wall_dist)), draw_start_end, side);
		// tex_step = 1.0 * IMG_HEIGHT / ((int)(HEIGHT / perp_wall_dist));

		// tex_pos = (draw_start_end.x - HEIGHT / 2 + ((int)(HEIGHT / perp_wall_dist)) / 2) * tex_step;

		// y_cnt = draw_start_end.x;
		// while (y_cnt < draw_start_end.y)
		// {
		// 	texture.y = (int)tex_pos & (IMG_HEIGHT - 1);
		// 	tex_pos += tex_step;

		// 	if (side == 0)
		// 	{
		// 		if (g->ray.x > 0)
		// 			g->buf[y_cnt][x_cnt] = ((int *)(g->tex.we.addr))[IMG_HEIGHT * texture.y + texture.x];
		// 		else
		// 			g->buf[y_cnt][x_cnt] = ((int *)(g->tex.ea.addr))[IMG_HEIGHT * texture.y + texture.x];
		// 	}
		// 	else
		// 	{
		// 		if (g->ray.y > 0)
		// 			g->buf[y_cnt][x_cnt] = ((int *)(g->tex.so.addr))[IMG_HEIGHT * texture.y + texture.x];
		// 		else
		// 			g->buf[y_cnt][x_cnt] = ((int *)(g->tex.no.addr))[IMG_HEIGHT * texture.y + texture.x];
		// 	}
		// 	y_cnt++;
		// }
		x_cnt++;
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

int	test(t_game *g)
{
	raycasting(g);
	draw_window(g);
	return (0);
}

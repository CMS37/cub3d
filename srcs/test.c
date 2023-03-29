/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:40:18 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/29 22:42:42 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycasting(t_game *g)
{
	int			x_cnt;
	t_vec_int	map;
	t_vec		delta_dist;
	t_vec		side_dist;
	t_vec_int	step;
	double		perp_wall_dist;
	int 		hit;
	int			side;
	int			line_hight;
	int			draw_start;
	int			draw_end;
	int			texture_num;
	t_vec_int	texture;
	double		wall_x;
	double		tex_step;
	double 		tex_pos;
	int			y_cnt;
	int			color;

	x_cnt = 0;	
	while (x_cnt < WIDTH)
	{
		g->ray.x = g->dir.x + g->plane.x * (2 * x_cnt / (double)WIDTH - 1);
		g->ray.y = g->dir.y + g->plane.y * (2 * x_cnt / (double)WIDTH - 1);
		map.x = (int)g->pos.x;
		map.y = (int)g->pos.y;
		delta_dist.x = fabs(1 / g->ray.x);
		delta_dist.y = fabs(1 / g->ray.y);

		if (g->ray.x < 0)
		{
			step.x = -1;
			side_dist.x = (g->pos.x - map.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (map.x + 1.0 - g->pos.x) * delta_dist.x;
		}
		if (g->ray.y < 0)
		{
			step.y = -1;
			side_dist.y = (g->pos.y - map.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (map.y + 1.0 - g->pos.y) * delta_dist.y;
		}

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
			if (g->map[map.x][map.y] > '0')
				hit = 1;
		}

		if (side == 0)
			perp_wall_dist = (map.x - g->pos.x + (1 - step.x) / 2) / g->ray.x;
		else
			perp_wall_dist = (map.y - g->pos.y + (1 - step.y) / 2) / g->ray.y;

		line_hight = (int)(HEIGHT / perp_wall_dist);
		
		draw_start = -line_hight / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_hight / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;

		if (side == 0)
			wall_x = g->pos.y + perp_wall_dist * g->ray.y;
		else
			wall_x = g->pos.x + perp_wall_dist * g->ray.x;
		wall_x -= floor(wall_x);

		texture.x = (int)(wall_x * (double)IMG_WIDTH);
		if (side == 0 && g->ray.x > 0)
			texture.x = IMG_WIDTH - texture.x - 1;
		if (side == 1 && g->ray.y < 0)
			texture.x = IMG_WIDTH - texture.x - 1;

		tex_step = 1.0 * IMG_HEIGHT / line_hight;

		tex_pos = (draw_start - HEIGHT / 2 + line_hight / 2) * tex_step;

		y_cnt = draw_start;
		while (y_cnt < draw_end)
		{
			texture.y = (int)tex_pos & (IMG_HEIGHT - 1);
			tex_pos += tex_step;
			
			if (side == 0)
			{
				if (g->ray.x > 0)
					texture_num = 3;
				else
					texture_num = 2;
			}
			else
			{
				if (g->ray.y > 0)
					texture_num = 1;
				else
					texture_num = 0;
			}

			if (texture_num == 0)
				color = ((int *)(g->tex.no.addr))[IMG_HEIGHT * texture.y + texture.x];
			else if (texture_num == 1)
				color = ((int *)(g->tex.so.addr))[IMG_HEIGHT * texture.y + texture.x];
			else if (texture_num == 2)
				color = ((int *)(g->tex.we.addr))[IMG_HEIGHT * texture.y + texture.x];
			else
				color = ((int *)(g->tex.ea.addr))[IMG_HEIGHT * texture.y + texture.x];
			g->buf[y_cnt][x_cnt] = color;
			y_cnt++;
		}

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
		while (x_cnt < HEIGHT)
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

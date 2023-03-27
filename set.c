/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:01:07 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/27 11:49:43 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_img(char **patch, char *tmp)
{
	if ((*patch))
		print_err("Check Map identifier");
	(*patch) = check_xpm_file(tmp);
}

void	load_img(t_game *g, t_info *info)
{
	g->tex.no.img = mlx_xpm_file_to_image(g->mlx, info->img.no, \
										&g->tex.no.width, &g->tex.no.height);\
	g->tex.so.img = mlx_xpm_file_to_image(g->mlx, info->img.so, \
										&g->tex.so.width, &g->tex.so.height);
	g->tex.we.img = mlx_xpm_file_to_image(g->mlx, info->img.we, \
										&g->tex.we.width, &g->tex.we.height);
	g->tex.ea.img = mlx_xpm_file_to_image(g->mlx, info->img.ea, \
										&g->tex.ea.width, &g->tex.ea.height);
	if (!g->tex.no.img || !g->tex.so.img || !g->tex.ea.img || !g->tex.we.img)
		print_err("Check XPM file!");
	g->tex.no.addr = mlx_get_data_addr(g->tex.no.img, &g->tex.no.bpp, \
										&g->tex.no.len, &g->tex.no.end);
	g->tex.so.addr = mlx_get_data_addr(g->tex.so.img, &g->tex.so.bpp, \
										&g->tex.so.len, &g->tex.so.end);
	g->tex.we.addr = mlx_get_data_addr(g->tex.we.img, &g->tex.we.bpp, \
										&g->tex.we.len, &g->tex.we.end);
	g->tex.ea.addr = mlx_get_data_addr(g->tex.ea.img, &g->tex.ea.bpp, \
										&g->tex.ea.len, &g->tex.ea.end);
}

static void	set_pos(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'N' || g->map[y][x] == 'S' || \
				g->map[y][x] == 'E' || g->map[y][x] == 'W')
			{
				g->pos.x = x;
				g->pos.y = y;
				// g->angle = 스폰방향에따라 바라보는방향 조정?
			}
			x++;
		}
		y++;
	}
	if (!g->pos.x || !g->pos.y)
		print_err("Wrong Map");
}

void	set_game(t_game *g, t_info *info)
{
	int	x;
	int	y;

	g->map = copy_map(info->map, info->size);
	g->f_color = info->f_color;
	if (!g->f_color)
		print_err("Floor RGB value ERR");
	g->c_color = info->c_color;
	if (!g->c_color)
		print_err("Ceiling RGB value ERR");
	set_pos(g);
	g->dir.x = -1;
	g->plane.y = 0.66;
	load_img(g, info);
}

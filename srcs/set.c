/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:01:07 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/30 01:38:47 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*check_xpm_file(char *tmp)
{
	int	fd;

	fd = open(tmp, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		print_err("Fail Open Xpm Files");
	}
	close(fd);
	return (ft_strdup(tmp));
}

void	set_img(char **patch, char *tmp)
{
	if ((*patch))
		print_err("NESW - Check Map identifier");
	(*patch) = check_xpm_file(tmp);
}

void	load_img(t_game *g, t_info *info)
{
	g->tex.no.img = mlx_xpm_file_to_image(g->mlx, info->img.no, \
										&g->tex.no.width, &g->tex.no.height);
	g->tex.so.img = mlx_xpm_file_to_image(g->mlx, info->img.so, \
										&g->tex.so.width, &g->tex.so.height);
	g->tex.we.img = mlx_xpm_file_to_image(g->mlx, info->img.we, \
										&g->tex.we.width, &g->tex.we.height);
	g->tex.ea.img = mlx_xpm_file_to_image(g->mlx, info->img.ea, \
										&g->tex.ea.width, &g->tex.ea.height);
	if (!g->tex.no.img || !g->tex.so.img || !g->tex.ea.img || !g->tex.we.img)
		print_err("Check XPM file!");
	g->tex.no.addr = (unsigned int *)mlx_get_data_addr(g->tex.no.img, &g->tex.no.bpp, \
										&g->tex.no.len, &g->tex.no.end);
	g->tex.so.addr = (unsigned int *)mlx_get_data_addr(g->tex.so.img, &g->tex.so.bpp, \
										&g->tex.so.len, &g->tex.so.end);
	g->tex.we.addr = (unsigned int *)mlx_get_data_addr(g->tex.we.img, &g->tex.we.bpp, \
										&g->tex.we.len, &g->tex.we.end);
	g->tex.ea.addr = (unsigned int *)mlx_get_data_addr(g->tex.ea.img, &g->tex.ea.bpp, \
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
			if (map_identi(g->map[y][x]))
				print_err("Map only use 10NESW");
			if (is_closed(g, x, y))
				print_err("Map is not closed");
			if (is_player(g->map[y][x]))
			{
				if (g->pos.x || g->pos.y)
					print_err("So many NSEW");
				g->pos.x = x + 0.5;
				g->pos.y = y + 0.5;
			}
			x++;
		}
		y++;
	}
}

void	set_game(t_game *g, t_info *info)
{
	g->map = copy_map(info->map, info->size);
	g->f_color = info->f_color;
	g->c_color = info->c_color;
	set_pos(g);
	if (g->pos.x == 0 || g->pos.y == 0)
		print_err("Wrong MAP!");
	g->dir.x = -1;
	g->plane.x = 0;
	g->plane.y = 0.66;
	load_img(g, info);
}

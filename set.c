/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:01:07 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/27 09:10:58 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_img(char **patch, char *tmp)
{
	if ((*patch))
		print_err("Check Map identifier");
	(*patch) = check_xpm_file(tmp);
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
			if (g->map[y][x] == 'N')
			{
				g->pos.x = x;
				g->pos.y = y;
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
	int x;
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
}

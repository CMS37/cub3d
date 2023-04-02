/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:42:44 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/02 17:24:54 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	turn_right(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->dir.x;
	g->dir.x = g->dir.x * cos(0.05) - g->dir.y * sin(0.05);
	g->dir.y = old_dir_x * sin(0.05) + g->dir.y * cos(0.05);
	old_plane_x = g->plane.x;
	g->plane.x = g->plane.x * cos(0.05) - g->plane.y * sin(0.05);
	g->plane.y = old_plane_x * sin(0.05) + g->plane.y * cos(0.05);
}

void	turn_left(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->dir.x;
	g->dir.x = g->dir.x * cos(-0.05) - g->dir.y * sin(-0.05);
	g->dir.y = old_dir_x * sin(-0.05) + g->dir.y * cos(-0.05);
	old_plane_x = g->plane.x;
	g->plane.x = g->plane.x * cos(-0.05) - g->plane.y * sin(-0.05);
	g->plane.y = old_plane_x * sin(-0.05) + g->plane.y * cos(-0.05);
}

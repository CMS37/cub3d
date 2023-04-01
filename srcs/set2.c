/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:51:27 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/01 16:54:43 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_dir_plane(t_game *g)
{
	if (g->map[(int)g->pos.y][(int)g->pos.x] == 'W')
	{
		g->dir.x += 1.0;
		g->plane.x = 0.0;
		g->plane.y = -0.66;
	}
	else if (g->map[(int)g->pos.y][(int)g->pos.x] == 'E')
	{
		g->dir.x += -1.0;
		g->plane.x = 0.0;
		g->plane.y = 0.66;
	}
	else if (g->map[(int)g->pos.y][(int)g->pos.x] == 'N')
	{
		g->dir.y += -1.0;
		g->plane.x = -0.66;
		g->plane.y = 0.0;
	}
	else if (g->map[(int)g->pos.y][(int)g->pos.x] == 'S')
	{
		g->dir.y += 1.0;
		g->plane.x = 0.66;
		g->plane.y = 0.0;
	}
}

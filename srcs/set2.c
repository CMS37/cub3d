/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:51:27 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/02 17:16:17 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_dir_plane(t_game *g)
{
	if (g->map[(int)g->pos.y][(int)g->pos.x] == 'W')
	{
		g->dir = (t_vec){-1.0, 0.0};
		g->plane = (t_vec){0.0, -0.66};
	}
	else if (g->map[(int)g->pos.y][(int)g->pos.x] == 'E')
	{
		g->dir = (t_vec){1.0, 0.0};
		g->plane = (t_vec){0.0, 0.66};
	}
	else if (g->map[(int)g->pos.y][(int)g->pos.x] == 'N')
	{
		g->dir = (t_vec){0.0, -1.0};
		g->plane = (t_vec){0.66, 0.0};
	}
	else if (g->map[(int)g->pos.y][(int)g->pos.x] == 'S')
	{
		g->dir = (t_vec){0.0, 1.0};
		g->plane = (t_vec){-0.66, 0.0};
	}
}

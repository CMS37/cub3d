/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:39:22 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/01 15:43:06 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_front(t_game *g)
{
	if (g->map[(int)g->pos.y][(int)(g->pos.x + g->dir.x * 0.05)] == '0')
		g->pos.x += g->dir.x * 0.05;
	if (g->map[(int)(g->pos.y + g->dir.y * 0.05)][(int)(g->pos.x)] == '0')
		g->pos.y += g->dir.y * 0.05;
}

void	move_back(t_game *g)
{
	if (g->map[(int)(g->pos.y)][(int)(g->pos.x - g->dir.x * 0.05)] == '0')
		g->pos.x -= g->dir.x * 0.05;
	if (g->map[(int)(g->pos.y - g->dir.y * 0.05)][(int)(g->pos.x)] == '0')
		g->pos.y -= g->dir.y * 0.05;
}

void	move_left(t_game *g)
{
	if (g->map[(int)(g->pos.y + g->dir.x * 0.05)][(int)(g->pos.x)] == '0')
		g->pos.y += g->dir.x * 0.05;
	if (g->map[(int)(g->pos.y)][(int)(g->pos.x - g->dir.x * 0.05)] == '0')
		g->pos.x -= g->dir.y * 0.05;
}

void	move_right(t_game *g)
{
	if (g->map[(int)(g->pos.y - g->dir.x * 0.05)][(int)(g->pos.x)] == '0')
		g->pos.y -= g->dir.x * 0.05;
	if (g->map[(int)(g->pos.y)][(int)(g->pos.x - g->dir.x * 0.05)] == '0')
		g->pos.x += g->dir.y * 0.05;
}

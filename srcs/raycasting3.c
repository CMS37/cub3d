/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:11:43 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/04 15:16:55 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_step_side_dist(t_game *g, t_ray *r, t_vec *delta_dist, \
t_vec *side_dist)
{
	if (g->ray.x < 0)
	{
		r->step.x = -1;
		side_dist->x = (g->pos.x - r->map.x) * delta_dist->x;
	}
	else
	{
		r->step.x = 1;
		side_dist->x = (r->map.x + 1.0 - g->pos.x) * delta_dist->x;
	}
	if (g->ray.y < 0)
	{
		r->step.y = -1;
		side_dist->y = (g->pos.y - r->map.y) * delta_dist->y;
	}
	else
	{
		r->step.y = 1;
		side_dist->y = (r->map.y + 1.0 - g->pos.y) * delta_dist->y;
	}
}

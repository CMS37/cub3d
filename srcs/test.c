/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:40:18 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/01 15:53:11 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

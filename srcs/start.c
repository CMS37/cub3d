/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:13:36 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/02 16:25:41 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

static int	end_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
	return (0);
}

static int	key_event(int input, t_game *g)
{
	if (input == KEY_ESC)
		end_game(g);
	if (input == KEY_W)
		move_front(g);
	if (input == KEY_S)
		move_back(g);
	if (input == KEY_D)
		move_right(g);
	if (input == KEY_A)
		move_left(g);
	if (input == KEY_ARROW_LEFT)
		turn_left(g);
	if (input == KEY_ARROW_RIGHT)
		turn_right(g);
	return (0);
}

char	**copy_map(char **map, int size)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * (size - 5));
	if (!tmp)
		return (NULL);
	i = 0;
	while (map[i + 6])
	{
		tmp[i] = ft_strdup(map[i + 6]);
		if (!tmp[i])
		{
			free_map(tmp);
			return (NULL);
		}
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	start_game(t_info *info)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, WIDTH, HEIGHT, "Cub3D");
	set_game(&g, info);
	free_info(info);
	g.window_img.img = mlx_new_image(g.mlx, WIDTH, WIDTH);
	g.window_img.addr = (unsigned int *)mlx_get_data_addr(g.window_img.img, \
					&g.window_img.bpp, &g.window_img.len, &g.window_img.end);
	mlx_loop_hook(g.mlx, &test, &g);
	mlx_hook(g.win, 17, 0, end_game, &g);
	mlx_hook(g.win, 2, 0, key_event, &g);
	mlx_loop(g.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:13:36 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/27 14:23:50 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	end_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
	return (0);
}

static int key_event(int input, t_game *g)
{
	if (input == KEY_ESC)
		end_game(g);
	if (input == KEY_A)
		;
	if (input == KEY_D)
		;
	if (input == KEY_W)
		;
	if (input == KEY_S)
		;
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

void	set_img(t_game *g, t_info *info)
{
	g->xpm.no = mlx_xpm_file_to_image(g->mlx, info->img.no, NULL, NULL); //need set w,h
	g->xpm.so = mlx_xpm_file_to_image(g->mlx, info->img.so, NULL, NULL);
	g->xpm.ea = mlx_xpm_file_to_image(g->mlx, info->img.ea, NULL, NULL);
	g->xpm.we = mlx_xpm_file_to_image(g->mlx, info->img.we, NULL, NULL);
}

void	start_game(t_info *info)
{
	t_game g;
	
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, WIDTH, HEIGHT, "Cub3D");
	g.map = copy_map(info->map, info->size);
	set_img(&g, info);
	//free(info) < make
	//put_img < make 
	mlx_hook(g.win, 17, 0, end_game, &g);
	mlx_hook(g.win, 2, 0, key_event, &g);
	mlx_loop(g.mlx);
}
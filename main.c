/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:06:31 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/22 16:13:12 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[++i])
			free(map[i]);
		free(map);
	}
}

static void	free_img(t_img *img)
{
	int	i;

	if (img->no)
		free(img->no);
	if (img->so)
		free(img->so);
	if (img->we)
		free(img->we);
	if (img->ea)
		free(img->ea);
	i = 0;
	while (++i < 4)
	{
		free(img->floor[i]);
		free(img->ceiling[i]);
	}
}

static void	free_info(t_info *info)
{
	free_map(info->map);
	free_img(&info->img);
}

static void	clear_info(t_info *info)
{
	info->size = 0;
	info->map = NULL;
	info->img.no = NULL;
	info->img.so = NULL;
	info->img.we = NULL;
	info->img.ea = NULL;
	info->img.floor = NULL;
	info->img.ceiling = NULL;
}

int	main(int argc, char **argv)
{
	t_info	info;

	clear_info(&info);
	parsing(argc, argv, &info);
	start_game(&info);
	free_info(&info);
	return (0);
}

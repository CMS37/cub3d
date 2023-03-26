/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:06:31 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/26 20:27:38 by min-cho          ###   ########seoul.kr  */
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

int	main(int argc, char **argv)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	parsing(argc, argv, &info);
	start_game(&info);
	free_info(&info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:06:31 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/02 15:56:56 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	if (map)
	{
		while (map[++i])
			free(map[i]);
		free(map);
	}
}

void	free_info(t_info *info)
{
	free_map(info->map);
	if (info->img.no)
		free(info->img.no);
	if (info->img.ea)
		free(info->img.ea);
	if (info->img.we)
		free(info->img.we);
	if (info->img.so)
		free(info->img.so);
}

int	main(int argc, char **argv)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	parsing(argc, argv, &info);
	start_game(&info);
	return (0);
}

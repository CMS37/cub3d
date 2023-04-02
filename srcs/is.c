/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:37:51 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/02 19:28:51 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_player(char c)
{
	const char	s[5] = "NESW";
	int			i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_map(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (1);
	if (map[y])
	{
		if (map[y][x] && map[y][x] != ' ')
			return (0);
	}
	return (1);
}

int	is_closed(t_game *g, int x, int y)
{
	const char	s[6] = "0NEWS";
	int			i;

	i = 0;
	while (s[i])
	{
		if (g->map[y][x] == s[i])
		{
			if (check_map(g->map, x + 1, y) || check_map(g->map, x - 1, y) || \
				check_map(g->map, x, y + 1) || check_map(g->map, x, y - 1))
				return (1);
		}
		i++;
	}
	return (0);
}

int	map_identi(char c)
{
	const char	s[8] = "10NESW \t";
	int			i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (0);
		i++;
	}
	return (1);
}

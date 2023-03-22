/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_err.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:22:55 by min-cho           #+#    #+#             */
/*   Updated: 2022/10/12 22:24:21 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_type(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_wrong_word(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'E' && \
			str[i] != 'C' && str[i] != 'P')
			break ;
		i++;
	}
	if (str[i] == '\0')
	{
		if (check_first_wall(str))
			map_err(1);
		return (0);
	}
	if (str[i] == '\n')
		return (0);
	return (1);
}

int	check_first_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] != '1' )
			return (1);
		i++;
	}
	return (0);
}

void	check_last_wall(char **str, t_map *map)
{
	int	i;

	i = 0;
	while (str[map->y][i + 1])
	{
		if (str[map->y][i] != '1' )
			map_err(1);
		i++;
	}
}

char	**check_err(int argc, char **argv, t_map *map)
{
	int		fd;

	if (argc != 2)
	{
		write(1, "Error\n Check argument\n", 23);
		exit(0);
	}
	if (check_file_type(argv[1]))
	{
		write(1, "Error\n Wrong file type\n", 24);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n Check map file\n", 23);
		exit(0);
	}
	clear_map(map);
	return (make_map(fd, map));
}

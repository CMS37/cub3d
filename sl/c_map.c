/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:06:10 by min-cho           #+#    #+#             */
/*   Updated: 2022/10/12 22:22:59 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_err(int i)
{
	if (i == 1)
		write(1, "Error\nThe wall is installed incorrectly\n", 41);
	else if (i == 2)
		write(1, "Error\nCan't use square map\n", 28);
	else if (i == 3)
		write(1, "Error\nCan't find object\n", 25);
	else if (i == 4)
		write(1, "Error\nJust make map using '01ECP'\n", 35);
	else if (i == 5)
		write(1, "Error\nCan't find map\n", 22);
	exit(0);
}

int	find_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	check_line(char *line, t_map *map)
{
	if (line[0] == '\n')
		return (0);
	if (!map->x)
	{
		map->x = (ft_strlen(line) - 1);
		if (check_first_wall(line))
			map_err(1);
	}
	if (line[0] != '1' || line[map->x - 1] != '1')
		map_err(1);
	if (check_wrong_word(line))
		map_err(4);
	map->exit += find_char(line, 'E');
	map->collect += find_char (line, 'C');
	map->player += find_char (line, 'P');
	map->y++;
	return (1);
}

void	check_last(t_map *map)
{
	if (!map->x)
		map_err(5);
	if (map->x == map->y)
		map_err(2);
	if (!map->exit || !map->collect || !map->player)
		map_err(3);
}

char	**make_map(int fd, t_map *map)
{
	char	*map_line;
	char	*line;
	char	*line2;
	char	**map_str;

	line = NULL;
	while (1)
	{
		map_line = get_next_line(fd);
		if (!map_line)
		{
			check_last(map);
			break ;
		}
		check_line(map_line, map);
		line2 = ft_strdup(line);
		free(line);
		line = ft_strjoin(line2, map_line);
		free(line2);
		free(map_line);
	}
	free(map_line);
	map_str = ft_split(line, '\n');
	free(line);
	return (map_str);
}

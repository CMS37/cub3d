/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:19:16 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/27 00:47:55 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*check_xpm_file(char *tmp)
{
	int	fd;

	fd = open(tmp, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		printErr("Fail Open Xpm Files");
	}
	close(fd);
	return (ft_strdup(tmp));
}

static int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (white_space(str[i]))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		i++;
	}
	while (white_space(str[i]))
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

static void	rgb_to_hex(int *hex, char **str)
{
	int		red;
	int		green;
	int		blue;

	if ((*hex))
		printErr("Check Map identifier");
	if (str_isdigit(str[0]) || str_isdigit(str[1]) || str_isdigit(str[2]))
		printErr("Check RGB value");
	red = ft_atoi(str[0]);
	green = ft_atoi(str[1]);
	blue = ft_atoi(str[2]);
	printf("%d,%d,%d\n", red, green, blue);
	if ((red < 0 || red > 255) || (green < 0 || green > 255) || \
		(blue < 0 || blue > 255))
		printErr("Input RGB value 0~255!");
	(*hex) = (red << 16) | (green << 8) | blue;
	free_map(str);
}

static void	set_img(char **patch, char *tmp)
{
	if ((*patch))
		printErr("Check Map identifier");
	(*patch) = check_xpm_file(tmp);
}

int	is_xpm(char *tmp, t_info *info)
{
	if (tmp[0] == 'N' && tmp[1] == 'O')
		set_img(&(info->img.no), tmp + 3);
	else if (tmp[0] == 'S' && tmp[1] == 'O')
		set_img(&(info->img.so), tmp + 3);
	else if (tmp[0] == 'W' && tmp[1] == 'E')
		set_img(&(info->img.we), tmp + 3);
	else if (tmp[0] == 'E' && tmp[1] == 'A')
		set_img(&(info->img.ea), tmp + 3);
	else if (tmp[0] == 'F')
		rgb_to_hex(&(info->f_color), ft_split(tmp + 2, ','));
	else if (tmp[0] == 'C')
		rgb_to_hex(&(info->c_color), ft_split(tmp + 2, ','));
	else
		return (0);
	return (1);
}

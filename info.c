/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:19:16 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/27 09:07:00 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*check_xpm_file(char *tmp)
{
	int	fd;

	fd = open(tmp, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		print_err("Fail Open Xpm Files");
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
		print_err("Check Map identifier");
	if (str_isdigit(str[0]) || str_isdigit(str[1]) || str_isdigit(str[2]))
		print_err("Check RGB value");
	red = ft_atoi(str[0]);
	green = ft_atoi(str[1]);
	blue = ft_atoi(str[2]);
	if ((red < 0 || red > 255) || (green < 0 || green > 255) || \
		(blue < 0 || blue > 255))
		print_err("Input RGB value 0~255!");
	(*hex) = (red << 16) | (green << 8) | blue;
	free_map(str);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:19:16 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/02 15:49:25 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	return (str[i] != '\0');
}

static int	split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	rgb_to_hex(int *hex, char **str)
{
	int	red;
	int	green;
	int	blue;

	if ((*hex))
		print_err("Floor - Check Map identifier");
	if (split_len(str) != 3 || str_isdigit(str[0]) || str_isdigit(str[1]) || \
		str_isdigit(str[2]))
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

int	set_info(char *tmp, t_info *info)
{
	if (!ft_strncmp(tmp, "NO", 2))
		set_img(&(info->img.no), tmp + 3);
	else if (!ft_strncmp(tmp, "SO", 2))
		set_img(&(info->img.so), tmp + 3);
	else if (!ft_strncmp(tmp, "WE", 2))
		set_img(&(info->img.we), tmp + 3);
	else if (!ft_strncmp(tmp, "EA", 2))
		set_img(&(info->img.ea), tmp + 3);
	else if (*tmp == 'F')
	{
		if (tmp[1] != ' ' || info->f_flag != 0)
			print_err("Floor - Check Map identifier");
		rgb_to_hex(&(info->f_color), ft_split(tmp + 2, ','));
		info->f_flag += 1;
	}
	else if (*tmp == 'C')
	{
		if (tmp[1] != ' ' || info->c_flag != 0)
			print_err("Ceiling - Check Map identifier");
		rgb_to_hex(&(info->c_color), ft_split(tmp + 2, ','));
		info->c_flag += 1;
	}
	else
		return (0);
	return (1);
}

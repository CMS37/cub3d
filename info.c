/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:19:16 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/26 21:52:26 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*check_xpm_file(char *tmp)
{
	int fd;

	fd = open(tmp, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		printErr("Fail Open Xpm Files");
	}
	close(fd);
	return(ft_strdup(tmp));
}

static void	rgb_to_hex(char **str, int *hex)
{
	int		red;
	int		green;
	int		blue;

	red = atoi(str[0]);
	green = atoi(str[1]);
	blue = atoi(str[2]);
	if ((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0 || blue > 255))
		printErr("Input RGB value 0~255!");
	(*hex) =  (red << 16) | (green << 8) | blue;
}

int	is_xpm(char *tmp, t_info *info)
{
	char	**s1 = NULL;

	if (tmp[0] == 'N' && tmp[1] == 'O')
	{
		if (info->img.no != NULL)
			printErr("Check Map identifier");
		info->img.no = check_xpm_file(tmp + 3);
	}
	else if(tmp[0] == 'S' && tmp[1] == 'O')
	{
		if (info->img.so != NULL)
			printErr("Check Map identifier");
		info->img.so = check_xpm_file(tmp + 3);
	}
	else if(tmp[0] == 'W' && tmp[1] == 'E')
	{
		if (info->img.we != NULL)
			printErr("Check Map identifier");
		info->img.we = check_xpm_file(tmp + 3);
	}
	else if(tmp[0] == 'E' && tmp[1] == 'A')
	{
		if (info->img.ea != NULL)
			printErr("Check Map identifier");
		info->img.ea = check_xpm_file(tmp + 3);
	}
	else if(tmp[0] == 'F')
	{
		if (info->img.floor != NULL)
			printErr("Check Map identifier");
		s1 = ft_split(tmp + 2, ',');
		rgb_to_hex(s1, &(info->f_color));
		free(s1);
	}
	else if(tmp[0] == 'C')
	{
		if (info->img.ceiling != NULL)
			printErr("Check Map identifier");
		s1 = ft_split(tmp + 2, ',');
		rgb_to_hex(s1, &(info->c_color));
		free(s1);
	}
	else
		return(0);
	return (1);	
}

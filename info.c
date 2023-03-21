/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:19:16 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/22 01:49:26 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*check_xpm_file(char *s1)
{
	int fd;

	fd = open(s1, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		printErr("Fail Open Xpm Files");
	}
	close(fd);
	return(ft_strdup(s1));
}

int	is_xpm(char *tmp, t_info *info)
{
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
		info->img.floor = ft_split(tmp + 2, ',');
	}
	else if(tmp[0] == 'C')
	{
		if (info->img.ceiling != NULL)
			printErr("Check Map identifier");
		info->img.ceiling = ft_split(tmp + 2, ',');
	}
	else
		return(0);
	return (1);	
}

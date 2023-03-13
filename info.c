/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:19:16 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/14 01:43:19 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_text(char *tmp, t_info *info)
{
	static cnt_no = 0;
	static cnt_so = 0;
	static cnt_we = 0;
	static cnt_ea = 0;
	static cnt_f = 0;
	static cnt_c = 0;
	
	if (tmp[0] == 'N' && tmp[1] == 'O')
	{
		if (cnt_no != 0)
			printErr("Check Map identifier");
		info->img.no = ft_strdup(tmp + 3);
		cnt_no++;
	}
	else if(tmp[0] == 'S' && tmp[1] == 'O')
	{
		if (cnt_so != 0)
			printErr("Check Map identifier");
		info->img.so = ft_strdup(tmp + 3);
		cnt_so++;
	}
	else if(tmp[0] == 'W' && tmp[1] == 'E')
	{
		if (cnt_we != 0)
			printErr("Check Map identifier");
		info->img.we = ft_strdup(tmp + 3);
		cnt_we++;
	}
	else if(tmp[0] == 'E' && tmp[1] == 'A')
	{
		if (cnt_ea != 0)
			printErr("Check Map identifier");
		info->img.ea = ft_strdup(tmp + 3);
		cnt_ea++;
	}
	else if(tmp[0] == 'F')
	{
		if (cnt_f != 0)
			printErr("Check Map identifier");
		info->img.floor = ft_split(tmp + 2, ',');
		cnt_f++;
	}
	else if(tmp[0] == 'C')
	{
		if (cnt_c != 0)
			printErr("Check Map identifier");
		info->img.ceiling = ft_split(tmp + 2, ',');
		cnt_c++;
	}
	else
		return(1);
	return (0);	
}

void	getInfo(int fd, t_info *info)
{
	char	*tmp;
	char	*line;
	char	*line2;

	line = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if(is_text(tmp, info))
		{
			if(check_line(tmp, info))
			{
				line2 = ft_strdup(line);
				free(line);
				line = ft_strjoin(line2, tmp);
				free(line2);
			}
		}
		free(tmp);
	}
	free(tmp);
	info->map = ft_split(line, '\n');
	free(line);
}

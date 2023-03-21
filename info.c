/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:19:16 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/21 21:11:36 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_xpm_file(int cnt, char *s1)
{
	int fd;

	if (cnt != 0)
		printErr("Check Map identifier");
	fd = open(s1, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		printErr("Fail Open Xpm Files");
	}
	close(fd);
}

int	is_xpm(char *tmp, t_info *info)
{
	static int cnt_no = 0;
	static int cnt_so = 0;
	static int cnt_we = 0;
	static int cnt_ea = 0;
	static int cnt_f = 0;
	static int cnt_c = 0;
	
	if (tmp[0] == 'N' && tmp[1] == 'O')
	{
		info->img.no = ft_strdup(tmp + 3);
		check_xpm_file(cnt_no, info->img.no);
		cnt_no++;
	}
	else if(tmp[0] == 'S' && tmp[1] == 'O')
	{
		info->img.so = ft_strdup(tmp + 3);
		check_xpm_file(cnt_so, info->img.so);
		cnt_so++;
	}
	else if(tmp[0] == 'W' && tmp[1] == 'E')
	{
		info->img.we = ft_strdup(tmp + 3);
		check_xpm_file(cnt_we, info->img.we);
		cnt_we++;
	}
	else if(tmp[0] == 'E' && tmp[1] == 'A')
	{
		info->img.ea = ft_strdup(tmp + 3);
		check_xpm_file(cnt_ea, info->img.ea);
		cnt_ea++;
	}
	else if(tmp[0] == 'F')
	{
		info->img.floor = ft_strdup(tmp + 3);
		cnt_f++;
	}
	else if(tmp[0] == 'C')
	{
		info->img.ceiling = ft_strdup(tmp + 3);
		cnt_c++;
	}
	else
		return(0);
	return (1);	
}

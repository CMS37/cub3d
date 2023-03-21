/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:09:04 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/22 02:05:32 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	checkType(char *str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	tmp = ft_substr(str, len - 4, len);
	if (ft_strcmp(tmp, ".cub"))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

static void	parse_av(int argc, char **argv)
{
	if (argc != 2)
		printErr("Check argument");
	if (checkType(argv[1]))
		printErr("Check File type");
}

static void	parse_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->size)
	{
		is_xpm(info->map[i], info); //여까진 맵옵션들 info에 입력완료
		i++;
	}
}

void	parsing(int argc, char **argv, t_info *info)
{
	parse_av(argc, argv);
	get_info(info, argv); //gnl + init info (before parse?)
	parse_info(info); //parse map > xpmfile
}

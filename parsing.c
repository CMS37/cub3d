/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:09:04 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/26 21:22:18 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	checkType(char *str, char *type)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	tmp = ft_substr(str, len - 4, len);
	if (ft_strcmp(tmp, type))
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
	if (checkType(argv[1], ".cub"))
		printErr("Check File type");
}

static void	parse_info(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->size)
		is_xpm(info->map[i], info);
	if (checkType(info->img.no, ".xpm") || checkType(info->img.so, ".xpm") || \
		checkType(info->img.we, ".xpm") || checkType(info->img.ea, ".xpm"))
		printErr("Check File type");
}

void	parsing(int argc, char **argv, t_info *info)
{
	parse_av(argc, argv);
	get_info(info, argv); //gnl + init info (before parse?)
	parse_info(info); //parse map > xpmfile
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:09:04 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/29 18:39:11 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_type(char *str, char *type)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	tmp = ft_substr(str, len - 4, len);
	if (!str)
		print_err("Check Map FILE");
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
		print_err("Check argument");
	if (check_type(argv[1], ".cub"))
		print_err("Check File type");
}

static void	parse_info(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->size)
		is_xpm(info->map[i], info);
	if (check_type(info->img.no, ".xpm") || check_type(info->img.so, ".xpm") || \
		check_type(info->img.we, ".xpm") || check_type(info->img.ea, ".xpm"))
		print_err("Check File type");
}

void	parsing(int argc, char **argv, t_info *info)
{
	parse_av(argc, argv);
	get_info(info, argv);
	parse_info(info);
}

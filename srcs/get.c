/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:50:34 by marvin            #+#    #+#             */
/*   Updated: 2023/04/02 15:48:12 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_info(t_info *info, char **argv)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_err("Fail open file");
	line = ft_strdup("");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (ft_strcmp(tmp, "\n"))
			info->size++;
		line = ft_strjoin(line, tmp);
		free(tmp);
	}
	info->map = ft_split(line, '\n');
	free(line);
	close(fd);
}

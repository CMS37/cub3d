/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:32:49 by min-cho           #+#    #+#             */
/*   Updated: 2023/04/01 16:54:57 by min-cho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_info(t_info *info, char **argv)
{
	int		fd;
	char	*tmp;
	char	*tmp2;
	char	*line;

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
		tmp2 = ft_strdup(line);
		free(line);
		line = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free(tmp);
	}
	info->map = ft_split(line, '\n');
	free(line);
	close(fd);
}

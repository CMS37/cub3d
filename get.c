/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:50:34 by marvin            #+#    #+#             */
/*   Updated: 2023/03/14 18:50:34 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	getInfo(t_info *info, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		printErr("Fail open file");
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
		{
			break;
		}
	}
	free(line);

	close(fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:50:34 by marvin            #+#    #+#             */
/*   Updated: 2023/03/21 22:37:53 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	getInfo(t_info *info, char **argv)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		printErr("Fail open file");
	i = 0;
	line = ft_strdup("");
	while(1)
	{
		tmp = get_next_line(fd);
		if(!tmp)
			break;
		tmp2 = ft_strdup(line);
		free(line);
		line = ft_strjoin(tmp2, tmp);
		free(tmp2);		
		i++;
	}
	info->size = i - 2;
	info->map = ft_split(line, '\n');
	close(fd);
}

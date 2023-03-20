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
	int		i;
	int		fd;
	char	*tmp;
	char	*tmp2;
	char	**line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		printErr("Fail open file");
	tmp = NULL;
	while(1)
	{
		tmp2 = get_next_line(fd);
		if(!tmp)
			break;
		ft_strcat(tmp, tmp2); //libft폴더 넣기
	}
	line = ft_split(tmp, '\n');
	free(tmp2);
	close(fd);
}

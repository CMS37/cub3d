/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:09:04 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/14 01:59:00 by min-cho          ###   ########seoul.kr  */
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

void	parsing(int ac, char **av)
{
	if (ac != 2)
		printErr("Check argument");
	if (checkType(av[1]))
		printErr("Check File type");
}

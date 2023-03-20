/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:13:04 by marvin            #+#    #+#             */
/*   Updated: 2023/03/20 19:13:04 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	is_op(char *line, t_info *info)
{
	static int i = 0;
	int		len;
	char	*tmp;
	char	*tmp2;

	if (i > 3)
		return ;
	len = ft_strlen(str);
	tmp = ft_substr(str, 0, 2);
	tmp2 = ft_substr(str, 4, len);
	if (ft_strcmp(tmp, "NO"))
		info->img.no = tmp2;
	else if(ft_strcmp(tmp,"SO"))
		info->img.so = tmp2;
	else if(ft_strcmp(tmp,"EA"))
		info->img.ea = tmp2;
	else if(ft_strcmp(tmp,"WE"))
		info->img.we = tmp2;
	free(tmp);
	i++;
}

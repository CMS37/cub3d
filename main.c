/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:06:31 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/14 02:09:25 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_info(t_info *info)
{
	if (info->map)
		free(map);
}
int main(int argc, char **argv)
{
	t_info	info;

	parsing(argc, argv, &info);
	//startGame(&info);
	//free_info(&info);
	return (0);
}
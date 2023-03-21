/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:06:31 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/21 20:50:20 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	free_info(t_info *info)
// {
// 	for(int i = 0; ;i++)
// 	{
// 		if (!info->map)
// 			break;
// 		free(info->map[i]);
// 	}
// }

int main(int argc, char **argv)
{
	t_info	info;

	info.map = NULL;
	parsing(argc, argv, &info);
	//startGame(&info);
	//free_info(&info);
	return (0);
}
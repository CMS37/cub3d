/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:52:17 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/14 01:32:46 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB_H
# define CUB_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>

# define SIZE	64

# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2
# define KEY_ESC	53

typedef struct s_img
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**floor;
	char	**ceiling;
} t_img;


typedef struct s_info
{
	char	**map;
	t_img	img;
} t_info;



void	printErr(char *s1);

#endif
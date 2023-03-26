/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:13:36 by min-cho           #+#    #+#             */
/*   Updated: 2023/03/26 19:50:28 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	end_game(t_game *g)
{
	//free(g) < make or just exit?
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
	return (0);
}

static int key_event(int input, t_game *g)
{
	if (input == KEY_ESC)
		end_game(g);
	if (input == KEY_A)
		;
	if (input == KEY_D)
		;
	if (input == KEY_W)
		;
	if (input == KEY_S)
		;
	return (0);
}

char	**copy_map(char **map, int size)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * (size - 5));
	if (!tmp)
		return(NULL);
	i = 0;
	while(map[i + 6])
	{
		tmp[i] = ft_strdup(map[i + 6]);
		if (!tmp[i])
		{
			free_map(tmp);
			return (NULL);
		}
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	set_img(t_game *g, t_info *info)
{
	g->xpm.no = mlx_xpm_file_to_image(g->mlx, info->img.no, NULL, NULL); //need set w,h
	g->xpm.so = mlx_xpm_file_to_image(g->mlx, info->img.so, NULL, NULL);
	g->xpm.ea = mlx_xpm_file_to_image(g->mlx, info->img.ea, NULL, NULL);
	g->xpm.we = mlx_xpm_file_to_image(g->mlx, info->img.we, NULL, NULL);
}

void	verline(t_game *g, int x, int start, int end, int color)
{
	int y;
	
	y = start;
	while (y <= end)
	{
		mlx_pixel_put(g->mlx, g->win, x, y, color);
		y++;
	}
}

void	testloop(t_game *g)
{
	int x;

	x = 0;
	while(x < WIDTH)
	{
		double cameraX = 2 * x / (double)WIDTH - 1; 
		g->ray.x = g->dir.x + g->plane.x * cameraX; //방향 벡터
		g->ray.y = g->dir.y + g->plane.y * cameraX;

		int mapX = (int)g->pos.x;
		int mapY = (int)g->pos.y;

		double sideX; //시작점 ~ 첫번째 x면을만나기까지의 광선거리
		double sideY;
		
		double distX = fabs(1 / g->ray.x); //첫번째 x면 ~ 다음 x면까지의 광선거리
		double distY = fabs(1 / g->ray.y);
		double distWall; //광선의 이동거리 계산에 필요

   	  	int stepX; //광선의 방향에 따라 x or y에 +1 혹은 -1로 저장
     	int stepY;

    	int hit = 0; //벽에 부딪쳤는지 여부
    	int side;

		if (g->ray.x < 0)
		{
			stepX = -1;
			sideX = (g->pos.x - mapX) * distX;
		}
		else
		{
			stepX = 1;
			sideX = (mapX + 1.0 - g->pos.x) * distX;
		}
		if (g->ray.y < 0)
		{
			stepY = -1;
			sideY = (g->pos.y - mapY) * distY;
		}
		else
		{
			stepY = 1;
			sideY = (mapY + 1.0 - g->pos.y) * distY;
		}
		//dda알고리즘 벽을 만나기 전 까지 step을 하나씩 이동하면서 탐색
		while (hit == 0)
		{
			if (sideX < sideY)
			{
				sideX += distX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideY += distY;
				mapY += stepY;
				side = 1;
			}
			if (g->map[mapY][mapX] > '0')
				hit = 1;
		}
		if (side == 0)
			distWall = (mapX - g->pos.x + (1 - stepX) / 2) / g->ray.x;
		else
			distWall = (mapY - g->pos.y + (1 - stepY) / 2) / g->ray.y;

		//그려야되는 벽의 높이 구하기 지금공식은 높이의 절반
		int lineHeight = (int)(HEIGHT / distWall); //벽의 중앙점

		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		
		//벽 칠하기
		int color;
		if (g->map[mapY][mapX] == '1')
			color = 0xFF0000; //빨강
		else if(g->map[mapY][mapX] == '2')
			color = 0xFFFFFF; //하양
		else
			color = 0xFFFF00; //노랑
		//사이드벽 색갈다르게
		if (side == 1)
			color = color / 2; 
		
		//수직선 그려주기
		verline(g, x, drawStart, drawEnd, color);
		x++;
	}
}

int	test(t_game *g)
{
	testloop(g);
	return (0);
}

void	start_game(t_info *info)
{
	t_game g;

	g.pos.x = 4;
	g.pos.y = 4;
	g.dir.x = -1;
	g.dir.y = 0;
	g.plane.x = 0;
	g.plane.y = 0.66;
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, WIDTH, HEIGHT, "Cub3D");
	g.map = copy_map(info->map, info->size);
	// set_img(&g, info);

	//testcode
	mlx_loop_hook(g.mlx, &test, &g);

	mlx_hook(g.win, 17, 0, end_game, &g);
	mlx_hook(g.win, 2, 0, key_event, &g);
	mlx_loop(g.mlx);
}

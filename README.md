-------------------
# 작업목록
#### 하면서 발견한 버그목록도 추가
+ vscode 디버그설정파일 추가해놨습니다. F5누르시면 map1.cub파일 기준 디버그 시작합니당

+ mlx_loop_hook 화면 4분할되는중

+ NESW값에 따라 바라보는 방향설정값 넣기
```C
static void	set_pos(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (map_identi(g->map[y][x]))
				print_err("Map only use 10NESW");
			if (is_closed(g, x, y))
				print_err("Map is not closed");
			if (is_player(g->map[y][x]))  //NESW면 TRUE 여기서 값넣음댈듯  
			{
				if (g->pos.x || g->pos.y)
					print_err("So many NSEW");
				g->pos.x = x + 0.5;
				g->pos.y = y + 0.5;
			}
			x++;
		}
		y++;
	}
}
```

-------------------
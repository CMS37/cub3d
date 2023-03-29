-------------------

+ vscode 디버그설정파일 추가해놨습니다. (실행 F5)
	+ cub3D 폴더가 작업영역으로 설정되어야함!

```
make n
```
+ norm검사 명령어 추가

+ MLX라이브러리 함수정리 [link](https://velog.io/@xhseb/solong-mlxMiniLibX-%ED%95%A8%EC%88%98-%EC%A0%95%EB%A6%AC)

-------------------
# 작업목록
#### 하면서 발견한 버그목록도 추가
+ mlx_loop_hook 화면 4분할되는중
	+ [link](https://stdbc.tistory.com/62)
+ 4분할은 고쳣는데 wasd키 안먹음..?
	+ 방향키도 완전히 뒤돌아볼려고 계속돌리면 팅김 

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
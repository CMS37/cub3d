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
+ mlx_loop_hook 화면 4분할되는중 - 해결
	+ [link](https://stdbc.tistory.com/62)


+ NESW값에 따라 바라보는 방향설정값 넣기
	+ WE방위는 들어갔는데 NS는 크랙남 - 해결
		+ 방향에 따라 pos 세팅시 plane(화면의 방향 벡터) 또한 각각 다르게 설정해줘야함

+ 가끔 벽 통과가 될 때가 있고 안될 때가 있는데 왜 그러는지 모르겠음

+ 함수 분할 중입니다. 레이캐스팅만 놈 맞춰주면 끝납니다!
	+ move.c(w, a, s, d moving), turn.c(left and right arrow turning), raycasting.c, 2.c(raycasting)
		+ 42 header 수정
-------------------
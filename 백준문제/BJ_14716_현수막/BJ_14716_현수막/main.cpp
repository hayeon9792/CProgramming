#include <stdio.h>

int res, M, N, map[250][250];
int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };

void dfs(int x, int y)
{
	map[x][y] = 0;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < M && ny < N
			&& map[nx][ny] == 1)
			dfs(nx, ny);
	}
	return;
}

int main()
{
	scanf("%d%d", &M, &N);

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	res = 0;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j])
			{
				dfs(i, j);
				res++;
			}
	printf("%d\n", res);
	return 0;
}
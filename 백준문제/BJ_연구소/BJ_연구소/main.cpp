#include <stdio.h>

typedef struct _info {
	int x, y;
}info;

int res, N, M, map[8][8], tmp[8][8];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

void mapcopy()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp[i][j] = map[i][j];
}

void maprecover()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] = tmp[i][j];
}

void bfs(int curi, int curj)
{
	info q[64];
	int front = 0, rear = 0;

	map[curi][curj] = 1;
	q[rear].x = curi;
	q[rear].y = curj;
	rear++;

	while (front != rear)
	{
		int ci, cj;
		ci = q[front].x;
		cj = q[front].y;
		front++;

		for (int d = 0; d < 4; d++)
		{
			int ni, nj;
			ni = ci + di[d];
			nj = cj + dj[d];
			if (ni < 0 || nj < 0 || ni >= N || nj >= M || map[ni][nj] != 0) continue;
			map[ni][nj] = 1;
			q[rear].x = ni;
			q[rear].y = nj;
			rear++;
		}
	}
	for (int i = 0; i < rear; i++)
	{
		q[i].x = 0; q[i].y = 0;
	}
}

void dfs(int curi, int curj, int num)
{
	if (num == 3)
	{
		mapcopy();

		for (int ii = 0; ii < N; ii++)
			for (int jj = 0; jj < M; jj++)
				if (map[ii][jj] == 2)
					bfs(ii, jj);

		int v = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 0) v++;
		if (v > res) res = v;

		maprecover();

		return;
	}
	if (num >= 3 || curi >= N || curj >= M) return;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] != 0) continue;
			map[i][j] = 1;
			dfs(i, j, num + 1);
			map[i][j] = 0;
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	res = -1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] != 0) continue;
			map[i][j] = 1;
			dfs(0, 0, 1);
			map[i][j] = 0;
		}
	}
	printf("%d\n", res);
	return 0;
}
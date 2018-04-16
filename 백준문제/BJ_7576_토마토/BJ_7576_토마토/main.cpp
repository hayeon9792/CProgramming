#include <stdio.h>

typedef struct _info {
	int x, y, l;
}info;

info q[1000000];
int front, rear, yet, N, M, map[1000][1000];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[1000][1000];

int bfs(int n)
{
	int num = n;
	while (front != rear)
	{
		int cx, cy, cl;
		cx = q[front].x;
		cy = q[front].y;
		cl = q[front].l;
		front++;

		for (int d = 0; d < 4; d++)
		{
			int nx, ny;
			nx = cx + dx[d];
			ny = cy + dy[d];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M
				|| visit[nx][ny] || map[nx][ny] != 0) continue;

			num++;
			if (num == yet) return cl + 1;

			visit[nx][ny] = true;
			map[nx][ny] = 1;
			q[rear].x = nx;
			q[rear].y = ny;
			q[rear].l = cl + 1;
			rear++;
		}
	}
	return 0;
}


int main()
{
	int v = 0;
	yet = 0, front = 0, rear = 0;
	scanf("%d%d", &M, &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) yet++;
			else if (map[i][j] == 1)
			{
				q[rear].x = i;
				q[rear].y = j;
				q[rear].l = 0;
				rear++;
				yet++;
				v++;
			}
		}

	int res = bfs(v);
	if (res == 0)
	{
		if (v == yet) printf("0\n");
		else printf("-1\n");
	}
	else printf("%d\n", res);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visit[i][j] = false;
		
	return 0;
}
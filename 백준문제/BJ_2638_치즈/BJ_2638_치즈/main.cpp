#include <stdio.h>
#include <string.h>

typedef struct _info {
	int x, y;
}info;
info q[10000];
int N, M, map[100][100], buf[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[100][100];

int outside()
{
	int front = 0, rear = 0;
	memset(visit, false, sizeof(visit));

	map[0][0] = 2;
	q[rear].x = 0;
	q[rear].y = 0;
	rear++;
	
	while (front != rear)
	{
		int cx, cy;
		cx = q[front].x;
		cy = q[front].y;
		front++;

		for (int d = 0; d < 4; d++)
		{
			int nx, ny;
			nx = cx + dx[d];
			ny = cy + dy[d];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] != 0) continue;

			map[nx][ny] = 2;
			q[rear].x = nx;
			q[rear].y = ny;
			rear++;
		}
	}

}

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			buf[i][j] = map[i][j];
		}



	return 0;
}
#include <stdio.h>
#include <string.h>

typedef struct _info {
	int x, y, l;
}info;
info q[10000];
int res, inum, N, map[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[100][100], check[10000];

void pnt()
{
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}

void bfs(int x, int y)
{
	int front = 0, rear = 0;
	map[x][y] = inum;
	q[rear].x = x;
	q[rear].y = y;
	q[rear].l = 0;
	rear++;
	
	while (front != rear)
	{
		int cx, cy, cl;
		cx = q[front].x;
		cy = q[front].y;
		front++;
		for (int d = 0; d < 4; d++)
		{
			int nx, ny;
			nx = cx + dx[d];
			ny = cy + dy[d];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] != 1) continue;
			map[nx][ny] = inum;
			q[rear].x = nx;
			q[rear].y = ny;
			rear++;
		}
	}
}

int go(int n)
{
	//n번 섬부터, 고고
	int front = 0, rear = 0;

	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] != n) continue;
			visit[i][j] = true;
			q[rear].x = i;
			q[rear].y = j;
			q[rear].l = 0;
			rear++;
		}

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
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny]) continue;

			visit[nx][ny] = true;

			if(map[nx][ny] == 0)
			{
				q[rear].x = nx;
				q[rear].y = ny;
				q[rear].l = cl + 1;
				rear++;
			}
			else
			{
				if (res > cl) res = cl; //제일 먼저 만나는 게 최소?!
				return 0;
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	inum = 1;

	//섬의 이름 붙이기
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == 1)
			{
				inum++;
				bfs(i, j);
			}
	for (int i = 2; i <= inum; i++) check[i] = false;

	res = 987654321;
	//각 섬마다 한칸씩 전진하면서 다른 섬과 만나면 그 길이 저장(답보다 작은 경우에만!)


	for (int n = 2; n <= inum; n++)
	{

		memset(visit, 0, sizeof(visit));
		check[n] = true;
		go(n);
	}

	printf("%d\n", res);
	return 0;
}

/*
10
1 1 1 0 0 0 0 0 1 1
1 1 1 1 0 0 0 0 0 1
1 0 1 1 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0


10
1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1
*/
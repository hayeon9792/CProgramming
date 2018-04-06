#include <stdio.h>
#define q_MAX 10000
// 방향이 전환되면 거울 설치!
int W, H, map[100][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char mapchar[100][101];
bool visit[100][100];
typedef struct info{
	int x, y, d, ch; //좌표, ch횟수
	info()
	{
		x = 0, y = 0, d=0, ch = 0;
	}
};

void pntvisit()
{
	printf("\n");
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			printf("%d ", visit[i][j]);
		printf("\n");
	}
}

int bfs(int x, int y)
{
	visit[x][y] = true;
	int front = 0, rear = 0;
	info q[q_MAX];
	q[rear%q_MAX].x = x;
	q[rear%q_MAX].y = y;
	q[rear%q_MAX].d = -1;
	q[rear%q_MAX].ch = -1;
	rear++;

	while (front != rear)
	{
		pntvisit();
		int cx, cy, cd, cch;
		cx = q[front%q_MAX].x;
		cy = q[front%q_MAX].y;
		cd = q[front%q_MAX].d;
		cch = q[front%q_MAX].ch;
		front++;

		for (int i = 0; i < 4; i++)
		{
			int nx, ny, nd;
			nx = cx + dx[i];
			ny = cy + dy[i];
			nd = i;

			if (nx >= 0 && ny >= 0 && nx < H && ny < W
				&& map[nx][ny] != 1 && !visit[nx][ny])
			{
				visit[nx][ny] = true;

				if (cd != nd) cch = cch + 1;

				if (map[nx][ny] == 2) return cch;

				q[rear%q_MAX].x = nx;
				q[rear%q_MAX].y = ny;
				q[rear%q_MAX].d = nd;
				q[rear%q_MAX].ch = cch;
				rear++;
			}		
		}
	}
	return -1;
}

int main()
{
	scanf("%d%d", &W, &H);
	for (int i = 0; i < H; i++)
		scanf("%s", &mapchar[i]);

	info start;
	
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			if (mapchar[i][j] == '.') map[i][j] = 0; // 갈 수 있음!
			else if (mapchar[i][j] == '*')map[i][j] = 1; // 벽!
			else if (mapchar[i][j] == 'C')
			{
				map[i][j] = 2; // C!
				start.x = i; start.y = j;
			}
		}
	int res = bfs(start.x, start.y);
	printf("%d\n", res);

	return 0;
}
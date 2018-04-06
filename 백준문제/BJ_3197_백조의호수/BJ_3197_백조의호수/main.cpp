#include <stdio.h>
#define q_MAX 15000

int res, R, C, map[1500][1500];
char tmp[1500][1501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[1500][1500];
typedef struct info{
	int x, y, d;
	info()
	{
		x = 0;
		y = 0;
		d = 0;
	}
};

info swan;
void pnt()
{
	printf("\n");
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			printf("%d ", map[i][j]);

		printf("\n");
	}
}
void copy()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			tmp[i][j] = map[i][j];
}
void recovery()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			map[i][j] = tmp[i][j];
}

int find_BFS(int x, int y) //한마리가 다른 한마리 찾으러감
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (visit[i][j]) visit[i][j] = false;

	info q[15000];
	int front = 0, rear = 0;
	q[rear%q_MAX].x = x;
	q[rear%q_MAX].y = y;
	q[rear%q_MAX].d = 0;
	rear++;
	visit[x][y] = true;

	while (front != rear)
	{
		int cx = q[front%q_MAX].x;
		int cy = q[front%q_MAX].y;
		int cd = q[front%q_MAX].d;
		front++;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < R && ny < C
				&& !visit[nx][ny] && map[nx][ny] != 1)
			{
				visit[nx][ny] = true;

				if (map[nx][ny] == 2) return 1; //성공
				
				else if (map[nx][ny] == 0)
				{
					q[rear%q_MAX].x = nx;
					q[rear%q_MAX].y = ny;
					q[rear%q_MAX].d = cd + 1;
					rear++;
				}
			}
		}
	}
	return 0; //실패
}

void melt() // 0,0부터 R-1,C-1까지 물이랑 닿은 빙판 녹임
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if(visit[i][j]) visit[i][j] = false;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 1 && !visit[i][j]) //1이면 빙판!
			{
				for (int cnt = 0; cnt < 4; cnt++) //네 방향에 물 있나 확인
				{
					int nx = i + dx[cnt];
					int ny = j + dy[cnt];
					if (nx >= 0 && ny >= 0 && nx < R&&ny < C
						&& map[nx][ny] == 0 && !visit[nx][ny]) //이미 녹은거 아닌지 확인
					{
						visit[i][j] = true;
						map[i][j] = 0;
						break;
					}

				}

			}
		}
	}
}

int main()
{
	scanf("%d%d", &R, &C);

	for (int i = 0; i < R; i++)
		scanf("%s", tmp[i]);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char x = tmp[i][j];
			if (x == '.') map[i][j] = 0; // 물은 0
			else if (x == 'X') map[i][j] = 1; //빙판은 1
			else if (x == 'L')
			{
				map[i][j] = 2; //백조는 2
				swan.x = i; swan.y = j; //두번째 백조 위치 저장
				
			}
		}
	}
	//pnt();
	res = 0;
	while (!find_BFS(swan.x,swan.y))
	{
		melt();
		//pnt();
		res++;
	}

	printf("%d\n", res);
	return 0;
}
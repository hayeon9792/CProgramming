#include <stdio.h>

int cost, res, N, map[10][10];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visit[10][10];

int check(int x, int y) // 씨를 심을 수 있는지  확인
{
	if (visit[x][y]) return 0;

	for (int j = 0; j < 4; j++)
	{
		int nx, ny;
		nx = x + dx[j];
		ny = y + dy[j];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N
			|| visit[nx][ny]) return 0;
	}
	return 1;
}

int action(int x, int y) // 꽃 한송이 피움
{
	if (check(x, y) == 0) return -1;

	int sum = 0;
	sum += map[x][y];
	visit[x][y] = true;

	for (int j = 0; j < 4; j++)
	{
		sum += map[x + dx[j]][y + dy[j]];
		visit[x + dx[j]][y + dy[j]] = true;
	}
	return sum;
}

void recovery(int x, int y)
{
	visit[x][y] = false;
	for (int j = 0; j < 4; j++)
		visit[x+dx[j]][y+dy[j]] = false;
}

void dfs(int i, int j, int n, int cost)
{
	if (n == 3)
	{
		if (cost < res) res = cost;
		return;
	}
	if (n >= 3) return;

	// 문제야 문제
	for (int x = 1; x < N - 1; x++)
	{
		for (int y = 1; y < N - 1; y++)
		{
			if (check(x, y))
			{
				int v = action(x, y);
				dfs(x, y, n + 1, cost + v);
				recovery(x, y);
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	 cost, res = 987654321;
	/*
	for (int f1 = 1; f1 < N-1; f1++)
		for (int f2 = 1; f2 < N-1; f2++)
		{
			cost = 0;

			if (visit[f1][f2]) continue;
			int v1= action(f1, f2);
			if (v1 == -1 || res < v1) continue;
			cost += v1;

			for (int f3 = 1; f3 < N-1; f3++)
				for (int f4 = 1; f4 < N-1; f4++)
				{
					if (visit[f3][f4]) continue;
					int v2 = action(f3, f4);
					if (v2 == -1 || res < v2) continue;
					cost += v2;

					for (int f5 = 1; f5 < N-1; f5++)
						for (int f6 = 1; f6 < N-1; f6++)
						{
							if (visit[f5][f6]) continue;
							int v3 = action(f5, f6);
							if (v3 == -1 || res < v3) continue;
							cost += v3;

							if (cost < res)res = cost;

							recovery(f5, f6);
							cost -= v3;
						}
					recovery(f3, f4);
					cost -= v2;
				}
			recovery(f1, f2);
		}*/
	dfs(1, 1, 0, 0);
	printf("%d\n", res);
	return 0;
}
/*
6
1 0 2 3 3 4
1 2 1 1 1 1
0 0 1 1 1 1
3 9 9 0 1 99
9 11 3 1 0 3
12 3 0 0 0 1

6
1 1 1 1 1 1
4 4 4 4 4 4
1 1 1 1 1 1
4 4 4 4 4 4
1 1 1 1 1 1
4 4 4 4 4 4
*/
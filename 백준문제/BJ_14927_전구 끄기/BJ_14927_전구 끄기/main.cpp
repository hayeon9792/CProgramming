#include <stdio.h>
#define MAX_N 18*18

int res, N;
bool visit[18], map[18][18], tmp[18][18];

void pntvisit()
{
	for (int i = 0; i < N; i++)
	{
		if (visit[i]) printf("1");
		else printf("0");
	}
	printf("\n");
}
void mapcopy()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmp[i][j] = map[i][j];
}

void maprecovery()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = tmp[i][j];
}

void click(int i, int j) // 2번 누르면 원상복귀
{
	map[i][j] = !map[i][j];
	if (i - 1 >= 0)map[i - 1][j] = !map[i - 1][j];
	if (i + 1 < N) map[i + 1][j] = !map[i + 1][j];
	if (j - 1 >= 0)map[i][j - 1] = !map[i][j - 1];
	if (j + 1 < N) map[i][j + 1] = !map[i][j + 1];
}

int start(int v)
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i - 1][j])
			{
				if(i>=0 && j>=0 &&i<N && j<N)
				click(i, j);
				v++;
			}
		}
	 }

	for (int j = 0; j < N; j++)
		if (map[N - 1][j])
		{
			v = 987654321;
			break;
		}

	return v;
}

void solve(int num)
{
	if (num == N)
	{
		//pntvisit();
		mapcopy();
		int v = 0;
		for (int j = 0; j < N; j++)
		{
			if (visit[j])
			{
				if (j >= 0 && j<N)
				click(0, j);
				v++;
			}
		}
		v = start(v);
		if (v < res)res = v;

		maprecovery();

		return;
	}
	if (num > N)return;

	visit[num] = true;
	solve(num + 1);
	visit[num] = false;

	solve(num + 1);
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	res = 987654321;
	solve(0);
	if (res == 987654321) res = -1;
	printf("%d\n", res);
	return 0;
}
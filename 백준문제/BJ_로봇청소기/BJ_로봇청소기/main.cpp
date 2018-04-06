#include <stdio.h>

int N, M, res, map[50][50];
int dx[4] = { -1,0,1,0 }; //북쪽기준!
int dy[4] = { 0,-1,0,1 };
int rx[4] = { 1,0,-1,0 };
int ry[4] = { 0,-1,0,1 };

void solve(int curr, int curc, int curd)
{
	for (int i = 0; i < 4; i++)
	{
		int nextd = (curd + (3 - i)) % 4;
		int nidx = (4 - nextd) % 4;
		int nextr = curr + dx[nidx];
		int nextc = curc + dy[nidx];

		if (nextr >= 0 && nextr < N&&nextc >= 0 && nextc < M
			&& !map[nextr][nextc]) //0이면
		{
			map[nextr][nextc] = 2;
			res++;
			solve(nextr, nextc, nextd);
			return;
		}
	}

	//탐색 후 후진
	int retr = curr + rx[curd];
	int retc = curc + ry[curd];

	if (retr >= 0 && retr < N &&retc >= 0 && retc < M
		&& map[retr][retc]!=1)
		solve(retr, retc, curd);

	return;
}
int main()
{
	int r, c, d;
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &r, &c, &d);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	res = 1;
	map[r][c] = 2;
	solve(r,c,d);
	printf("%d\n", res);
	return 0;
}


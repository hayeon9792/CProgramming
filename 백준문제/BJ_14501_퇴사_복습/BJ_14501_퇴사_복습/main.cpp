#include <stdio.h>

int res, N, T[15],P[15];

void dfs(int day, int cost)
{
	if (day <= N && cost > res)
		res = cost;
	if (day >= N) return;

	dfs(day + T[day], cost + P[day]);
	dfs(day + 1, cost);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &T[i], &P[i]);
	res = 0;
	dfs(0, 0);
	printf("%d\n", res);
	return 0;
}
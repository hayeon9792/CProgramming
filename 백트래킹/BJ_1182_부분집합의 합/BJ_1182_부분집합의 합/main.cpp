#include <stdio.h>

int bitmask, res, N, S;
int num[20];

void dfs(int idx, int sum)
{
	if (sum == S) res++;
	if (idx == N) return;

	dfs(idx + 1, sum + num[idx]);
	dfs(idx + 1, sum);
}

int main(void)
{
	res = 0;
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	dfs(0, 0);
	printf("%d\n", res);
}
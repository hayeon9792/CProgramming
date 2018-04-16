#include <stdio.h>

int res, N, K, d[100001];

void dfs(int n, int l)
{
	if (n == K && res > l)
	{
		res = l;
		return;
	}
	if (n >= 2*K || n < 0 || n > 100000 || res <= l) return;
	else
	{
		if (2 * n <= K || 2 * n - K + 1 < K - n) dfs(n * 2, l + 1); //순간이동

			if (n < K) dfs(n + 1, l + 1); //앞으로
			dfs(n - 1, l + 1); //뒤로
		
	}
}

int main()
{
	//순간이동, X+1, X-1;
	scanf("%d%d", &N, &K);

	res = 987654321;
	if (N >= K) res = N - K;
	else dfs(N, 0);
	printf("%d\n", res);
	return 0;
}
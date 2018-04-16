#include <stdio.h>

int mask, N, M, num[8];
bool visit[1 << 8];

void dfs(int idx, int n)
{
	if (n == M)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (mask&(1 << i) && !visit[mask])
			{
				visit[mask] = true;
				printf("%d", num[i]);
				cnt++;
				if (cnt != M) printf(" ");
				else printf("\n");
			}
		}
		return;
	}
	if (n >= M || idx >= N) return;

	mask |= (1 << idx);
	dfs(idx + 1, n + 1);
	mask &= ~(1 << idx);

	dfs(idx + 1, n);
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	mask = 0;

	dfs(0, 0);

	return 0;
}
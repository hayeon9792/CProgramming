#include <stdio.h>

int n, d[1000001];

/*
int dfs(int n)
{
	if (n == 1) return 0; //���� ���� ������ �����ϱ�!
	if (d[n] > 0) return d[n];//��� �ȰŸ� �װ� ��������
	d[n] = dfs(n - 1) + 1; // ���� 1. -1
	if (n % 2 == 0)
	{
		int tmp = dfs(n / 2) + 1;
		if (d[n] > tmp) d[n] = tmp;
	}
	if (n % 3 == 0)
	{
		int tmp = dfs(n / 3) + 1;
		if (d[n] > tmp) d[n] = tmp;
	}
	return memo[n];
}*/

int main()
{
	scanf("%d", &n);

	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)  d[i] = d[i / 2] + 1;
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) d[i] = d[i / 3] + 1;
	}

	printf("%d\n", d[n]);

	return 0;
}
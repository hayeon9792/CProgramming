#include <stdio.h>
#include <stdlib.h>

float ef[1000];
int N, res, T[1000], S[1000];

/*void dfs(int num, int cost, int cnt)
{
	if (num == N && cost <= res)
	{
		//���� ����
	}
	if (num >= N || cost > res) return;

	// �Ϸ� ���� ������, check ������ �ֵ� �� ���������
	check[cnt++] = num;
	for (int i = 0; i < N; i++)
		if (!check[i]) cost += (T[num] * S[i]);
	dfs(num + 1, cost, cnt);
	for (int i = 0; i < N; i++)
		if (!check[i]) cost -= (T[num] * S[i]);
	check[--cnt] = 0;

	dfs(num + 1, cost, cnt);
}*/

int main()
{
	res = 987654321;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &T[i], &S[i]);
		ef[i]=(float)S[i] / (float)T[i]; //���� ȿ������ ����
	}

	qsort(ef, N);


	return 0;
}
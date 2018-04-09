#include <stdio.h>
#include <stdlib.h>

float ef[1000];
int N, res, T[1000], S[1000];

/*void dfs(int num, int cost, int cnt)
{
	if (num == N && cost <= res)
	{
		//갱신 조건
	}
	if (num >= N || cost > res) return;

	// 하루 지날 때마다, check 안켜진 애들 다 더해줘야함
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
		ef[i]=(float)S[i] / (float)T[i]; //일의 효율도를 저장
	}

	qsort(ef, N);


	return 0;
}
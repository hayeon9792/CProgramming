#include <stdio.h>

int N, num[1000001];

int main()
{
	scanf("%d", &N);
	int max = 0, v;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &v);
		num[v] = num[v - 1] + 1;
		max = (max < num[v]) ? num[v] : max;
	}
	printf("%d\n", N-max);
	return 0;
}
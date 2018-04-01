#include <stdio.h>
/*
선택정렬
원리: 가장 작은 것을 선택해서 제일 앞으로 보낸다.
복잡도: N*(N+1)/2 번의 연산, 따라서 O(N^2)
*/

int N, num[100];

int main(void)
{
	int i, j, temp, min, idx;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);

	for (i = 0; i < N; i++)
	{
		min = 987654321;
		for (j = i; j < N; j++)
		{
			if (min > num[j])
			{
				min = num[j];
				idx = j;
			}
		}
		temp = num[i];
		num[i] = num[idx];
		num[idx] = temp;
	}

	for (i = 0; i < N; i++)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}
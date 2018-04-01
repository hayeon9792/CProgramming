//#include <stdio.h>
/*
버블정렬
원리: 바로 가까이에 있는 두 숫자끼리 비교하여 작은 숫자를 앞으로 보냄
복잡도: 연산이 가장 비효율적!!, O(N^2)
*/
/*
int N, num[100];

int main(void)
{
	int i, j, tmp;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - 1-i; j++)
		{
			if (num[j] > num[j + 1]) //부등호를 바꾸면 내림차순 정렬
			{
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}

		for (i = 0; i < N; i++)
			printf("%d ", num[i]);

		printf("\n");
	return 0;
}*/
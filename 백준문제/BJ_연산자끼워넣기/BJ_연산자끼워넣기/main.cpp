#include <stdio.h>

int min, max, N, num[11], op[4];

int solve(int n, int res)
{
	if (n > N - 1)
	{
		if (res < min) min = res;
		if (res > max) max = res;
		return 0;
	}

	for (int i = 0; i < 4; i++)
	{
		if (op[i]) //실행조건
		{
			op[i] -= 1;
			//재귀-조합 구현
			if (i == 0) solve(n + 1, res + num[n]);
			if (i == 1) solve(n + 1, res - num[n]);
			if (i == 2) solve(n + 1, res * num[n]);
			if (i == 3) solve(n + 1, res / num[n]);
			
			op[i] += 1; //보상
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	for (int i = 0; i < 4; i++)
		scanf("%d", &op[i]);

	min = 987654321;
	max = -987654321;

	solve(1, num[0]);

	printf("%d\n%d\n", max, min);

	return 0;
}
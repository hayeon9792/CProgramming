#include <stdio.h>

int res, N, S[21][21];
bool sel[21];

int q()
{
	int n = 0;
	for (int i = 1; i <= N; i++)
		if (sel[i]) n++;

	return n;
}

int diff()
{
	int sA = 0, sB = 0, dif = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			if (sel[i] && sel[j] && i != j)
			{
				sA += S[i][j];
				sA += S[j][i];
			}
			else if (!sel[i] && !sel[j] && i != j)
			{
				sB += S[i][j];
				sB += S[j][i];
			}
		}
	}

	dif = sA - sB;

	return (dif > 0) ? dif : -dif;
}

int solve(int n, int idx) //n=선택되는 사람
{
	if (n > N + 1 || n < 0) return 0;

	if(q()==N/2)
	{
		int v = diff();
		if (v < res) res = v;
		
		return 0;
	}

	sel[n] = true;
	solve(n + 1, idx + 1); //n을 선택
	sel[n] = false;
	
	solve(n + 1, idx); //n을 선택X

}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &S[i][j]);

	res = 987654321;
	solve(1, 1);
	printf("%d\n", res);

	return 0;
}

#include <stdio.h> //น้มุ 13458

long long N, A[1000000], B, C;

long long solve()
{
	long long res = N;
	for (int i = 0; i < N; i++)
	{
		A[i] -= B;
		if (A[i] > 0)
		{
			res += (A[i] / C);
			if (A[i] % C > 0)
			{
				res++;
			}
		}
	}
	return res;
}

int main()
{
	scanf("%lld", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &A[i]);
	
	scanf("%lld%lld", &B, &C);

	printf("%lld\n", solve());

	return 0;
}


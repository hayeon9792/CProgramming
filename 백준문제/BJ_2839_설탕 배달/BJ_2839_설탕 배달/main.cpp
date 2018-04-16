#include <stdio.h>

int N, d[50001];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i <= N; i++) d[i] = -1;
	d[0] = 0;
	d[3] = 1;
	for (int i = 4; i <= N; i++)
	{
		if (i % 3 == 0 && i % 5 != 0) d[i] = d[i - 3] + 1;
		else if (i % 3 != 0 && i % 5 == 0) d[i] = d[i - 5] + 1;
		else d[i] = d[i - 3] + 1 > d[i - 5] + 1 ? d[i - 5] + 1 : d[i - 3] + 1;
	}
	if (d[N] == 0) d[N] = -1;
	printf("%d\n", d[N]);
	return 0;
}
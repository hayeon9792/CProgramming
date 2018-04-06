/*#include <stdio.h>

float res;
int Rmtsum, casesum, Y1, Y2, Rmt[11], Eod[11];
int card[20] = { 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10 };
int count[11];
bool visit[20];

void mtable(int idx, int n)
{
	if (n == 2 && idx < 20)
	{
		int cnt = 0, a[2];
		for (int i = 0; i < 20; i++)
		{
			if (visit[i])
			{
				a[cnt] = card[i];
				cnt++;
			}
			if (cnt == 2) break;
		}

		if (a[0] == a[1]) Eod[a[0]]++;
		else
		{
			cnt = a[0] + a[1];
			cnt = cnt % 10;
			Rmt[cnt]++;
			Rmtsum++;
		}

		return;
	}
	if (idx >= 20 || n >= 2) return;

	visit[idx] = true;
	mtable(idx + 1, n + 1);
	visit[idx] = false;

	mtable(idx + 1, n);

	return;
}

int main()
{
	scanf("%d%d", &Y1, &Y2);
	visit[Y1] = true, visit[Y2] = true;
	mtable(0, 0);
	casesum = Rmtsum + 10;

	if (Y1 == Y2)
	{
		int lose = 0;
		lose = 10 - Y1;
		res = 1 - ((float)lose / (float)casesum);
	}
	else
	{
		int lose = 0, q = 0, p = (Y1 + Y2) % 10;
		for (int i = 0; i < p; i++)
			q += (Rmt[i]);
		q -= 1;
		res = 1 - ((float)lose / (float)casesum);
	}
	printf("%.3lf\n", res);
	return 0;
}*/
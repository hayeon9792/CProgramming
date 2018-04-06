#include <stdio.h>

float res;
int Y1, Y2, count[11];

int main()
{
	int caseall = 0, win = 0;

	scanf("%d%d", &Y1, &Y2);
	for (int i = 1; i <= 10; i++)
		count[i] = 2;
	
	count[Y1]--;
	count[Y2]--;

	for (int ii = 1; ii <= 20; ii++)
	{
		int i;
		if (ii > 10) i = ii - 10;
		else i = ii;

		if (count[i] <= 0) continue;
		count[i]--;

		for (int jj = 1; jj <= 20; jj++)
		{
			int j;
			if (jj > 10) j = jj - 10;
			else j = jj;

			if (count[j] <= 0) continue;
			count[j]--;

			caseall++;

			if (Y1 == Y2) // ¿µÇÐÀÌ ¶¯ÀÏ ¶§
			{
				if (i != j) win++;
				else if (i == j && i < Y1) win++;
			}
			else //²ýÀÏ ¶§
			{
				if (i != j)

				{
					int s1 = Y1 + Y2, s2 = i + j;
					s1 = s1 % 10;
					s2 = s2 % 10;
					if (s1 > s2)win++;
				}
			}
			count[j]++;
		}
		count[i]++;
	}
	res = (float)win / (float)caseall;
	printf("%.3lf\n", res);
	return 0;
}
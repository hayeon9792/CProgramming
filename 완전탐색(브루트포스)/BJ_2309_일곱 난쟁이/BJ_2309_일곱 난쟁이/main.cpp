#include <stdio.h>

int num[9];
bool count[101];

int main(void)
{
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
		count[num[i]] = true;
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			int v = (num[i] + num[j]);
			sum -= v;
			if (sum == 100)
			{
				count[num[i]] = false;
				count[num[j]] = false;
				for (int i = 1; i <= 100; i++)
					if (count[i]) printf("%d\n", i);

				return 0;
			}
			else sum += v;
		}
	}
	return 0;
}

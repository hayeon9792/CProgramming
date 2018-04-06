/*#include <stdio.h>
//돌리면서 하는경우-> 틀림
//N=0, S=1
//1=시계(head--), -1=반시계(head++)
int k, res, W[4][8];
int head[4] = { 0, }; //12시 방향 값 저장
int s[4] = { 0, };

int left(int i) { return (head[i] + 6) % 8; }
int right(int i) { return (head[i] + 2) % 8; }

int pow(int i)
{
	int sum = 1;
	if (i == 0) return sum;
	else
	{
		for (int cnt = 1; cnt <= i; cnt++)
			sum = sum * 2;
	}
	return sum;
}

int solve(int num, int dir)
{
	//극 다른지 확인!
	int i = num, idir = dir, j = num, jdir = dir;
	if (i >= 1) //왼쪽 확인
	{
		while (i != 0)
		{
			int l = left(i), r = right(i - 1);
			if (W[i][l] != W[i - 1][r])
			{
				idir *= -1;
				s[i - 1] = idir;
				for (int i = 0; i < 4; i++)
				{
					if (s[i] == 1)
					{
						head[i] = (head[i] + 7) % 8;
						s[i] = 0;
					}
					else if (s[i] == -1)
					{
						head[i] = (head[i] + 1) % 8;
						s[i] = 0;
					}
				}
				i--;
			}
			else
				break;
		}
	}

	if (j <= 2) //오른쪽 확인
	{
		while (j != 3)
		{
			int l = left(j + 1), r = right(j);
			if (W[j][r] != W[j + 1][l])
			{
				jdir *= -1;
				s[j + 1] = jdir;
				for (int i = 0; i < 4; i++)
				{
					if (s[i] == 1)
					{
						head[i] = (head[i] + 7) % 8;
						s[i] = 0;
					}
					else if (s[i] == -1)
					{
						head[i] = (head[i] + 1) % 8;
						s[i] = 0;
					}
				}
				j++;
			}
			else
				break;
		}
	}

	return 0;
}

int main()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &W[i][j]);
	k = 0;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int num, dir;
		scanf("\n%d %d", &num, &dir);
		s[num - 1] = dir;
		solve(num - 1, dir);
	}
	res = 0;
	for (int i = 0; i < 4; i++)
	{
		if (W[i][head[i]] == 1)
			res += pow(i);
	}
	printf("%d\n", res);
	return 0;
}
*/
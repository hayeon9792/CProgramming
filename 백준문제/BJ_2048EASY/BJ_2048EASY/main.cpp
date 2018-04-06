#include <stdio.h>

int N, res, map[21][21], tmp[21][21];

void pnt()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			printf("%2d ", map[i][j]);
		printf("\n");
	}

	printf("\n------------------------\n");
}

void copy() //¸Ê ÃÊ±âÈ­
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] = tmp[i][j];
}

int count() //ÃÖ´ñ°ª Å½»ö
{
	int max = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (map[i][j] > max)max = map[i][j];
	return max;
}

void moveUP()
{
	for (int j = 1; j <= N; j++)
	{
		for (int i = 1; i < N; i++)
		{
			if (map[i + 1][j])
			{
				if (map[i][j] == map[i + 1][j] && map[i][j] != 0)
				{
					map[i][j] *= 2;
					map[i + 1][j] = 0;
				}
			}
			else
			{
				map[i + 1][j] = map[i][j];
				map[i][j] = 0;
			}
		}
		int cnt = 1;
		for (int i = 1; i <= N; i++)
		{
			if (map[i][j])
			{
				map[cnt][j] = map[i][j];
				if(cnt!=i) map[i][j] = 0;
				cnt++;
			}
		}
	}
}

void moveDOWN()
{
	for (int j = 1; j <= N; j++)
	{
		for (int i = N; i > 1; i--)
		{
			if (map[i - 1][j])
			{
				if (map[i][j] == map[i - 1][j] && map[i][j] != 0)
				{
					map[i][j] *= 2;
					map[i - 1][j] = 0;
				}
			}
			else
			{
				map[i - 1][j] = map[i][j];
				map[i][j] = 0;
			}
		}
		int cnt = N;
		for (int i = N; i >= 1; i--)
		{
			if (map[i][j])
			{
				map[cnt][j] = map[i][j];
				if (cnt != i) map[i][j] = 0;
				cnt--;
			}
		}
	}
}

void moveLEFT()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (map[i][j + 1])
			{
				if (map[i][j] == map[i][j + 1] && map[i][j] != 0)
				{
					map[i][j] *= 2;
					map[i][j + 1] = 0;
				}
			}
			else
			{
				map[i][j + 1] = map[i][j];
				map[i][j] = 0;
			}
		}
		int cnt = 1;
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j])
			{
				map[i][cnt] = map[i][j];
				if (cnt != j) map[i][j] = 0;
				cnt++;
			}
		}
	}
}

void moveRIGHT()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = N; j > 1; j--)
		{
			if (map[i][j - 1])
			{
				if (map[i][j] == map[i][j - 1] && map[i][j] != 0)
				{
					map[i][j] *= 2;
					map[i][j - 1] = 0;
				}
			}
			else
			{
				map[i][j - 1] = map[i][j];
				map[i][j] = 0;
			}
		}
		int cnt = N;
		for (int j = N; j >= 1; j--)
		{
			if (map[i][j])
			{
				map[i][cnt] = map[i][j];
				if (cnt != j) map[i][j] = 0;
				cnt--;
			}
		}
	}
}

void solve(int n)
{
	if (n == 1) moveUP();
	else if (n == 2)moveDOWN();
	else if (n == 3)moveLEFT();
	else if (n == 4)moveRIGHT();
}


int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &tmp[i][j]);

	res = 0;

	for (int a = 1; a <= 4; a++)
		for (int b = 1; b <= 4; b++)
			for (int c = 1; c <= 4; c++)
				for (int d = 1; d <= 4; d++)
					for (int e = 1; e <= 4; e++)
					{
						copy();
						solve(a);
						solve(b);
						solve(c);
						solve(d);
						solve(e);
						int v = count();
						if (res < v)res = v;
					}

	printf("%d\n", res);
	return 0;
}

/*
5
4 2 8 4 4
16 16 8 4 4
2 2 8 4 8
2 2 8 4 4
4 4 16 8 4


6
2 2 2 2 2 2 
2 0 2 2 0 0 
0 0 0 0 2 0
0 0 2 0 2 0
2 2 2 2 2 2
2 2 2 2 2 2

5
2 2 4 8 16
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
2 2 4 8 16

*/
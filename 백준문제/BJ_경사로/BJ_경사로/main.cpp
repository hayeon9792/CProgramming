#include <stdio.h>

int N, L, res, curH;
int map[100][100];
bool check[100];

void rev() //��� ������
{
	int temp = 0;
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
		{
			temp = map[i][j];
			map[i][j] = map[j][i];
			map[j][i] = temp;
		}
}

int solve(int x) //��->x��, ��->y��
{
	int pos = 0;
	int height = map[x][pos];
	for (int i = 0; i < N; i++) check[i] = false;

	while (pos <= N)
	{
		if (pos + 1 >= N)
		{
			res++; return 0;
		}

		else if (map[x][pos + 1] == height) pos++; //������ Ȯ�� ���� 1��ŭ �̵�

		else if (map[x][pos + 1] == height - 1)
		{
			for (int j = pos + 1; j <= pos + L; j++)
			{
				if (map[x][j] != (height - 1) || j >= N) return 0;  //��==height-1�� Ȯ��
				else check[j] = true; //�տ� �� �� üũ �ʿ�
			}

			pos += L;
		}
		else if (map[x][pos + 1] == height + 1)
		{
			for (int j = pos - (L - 1); j <= pos; j++)
				if (map[x][j] != height || j < 0 || check[j]) return 0;  //��==height�� Ȯ��

			pos++;
		}
		else return 0;

		height = map[x][pos];
	}
	return 0;
}

int main()
{
	scanf("%d%d", &N, &L);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	
	res = 0;

	for (int i = 0; i < N; i++)
		solve(i);
	
	rev();

	for (int i = 0; i < N; i++)
		solve(i);

	printf("%d\n", res);
	return 0;
}
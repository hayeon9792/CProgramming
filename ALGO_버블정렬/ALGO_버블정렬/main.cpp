//#include <stdio.h>
/*
��������
����: �ٷ� �����̿� �ִ� �� ���ڳ��� ���Ͽ� ���� ���ڸ� ������ ����
���⵵: ������ ���� ��ȿ����!!, O(N^2)
*/
/*
int N, num[100];

int main(void)
{
	int i, j, tmp;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - 1-i; j++)
		{
			if (num[j] > num[j + 1]) //�ε�ȣ�� �ٲٸ� �������� ����
			{
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}

		for (i = 0; i < N; i++)
			printf("%d ", num[i]);

		printf("\n");
	return 0;
}*/
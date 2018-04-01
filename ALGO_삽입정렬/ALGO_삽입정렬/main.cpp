#include <stdio.h>
#include <string.h>
/*
��������
�񱳴���� 2��~N���� �÷����� 2,3,4,...,N��° ���� �ڸ��� ã�� ����
5 1 6 4 2 3
(5 1) 6 4 2 3 -> (1 5) 6 4 2 3
(1 5 6) 4 2 3 -> (1 5 6) 4 2 3
(1 5 6 4) 2 3 -> (1 4 5 6) 2 3
...

���� ������ ���ĵ� �����Ϳ� ���ؼ��� ������ N(N-1)/2 �� �ݺ�
���� ������ �ּ�(���ĵ� ������)-> N-1 /�־�-> N(N-1)/2 
����, �Ȱ��� O(N^2)������, ��������>���� ���� 
*/
void InsertionSort(int Dataset[], int Length)
{
	int i, j, value = 0;

	for (i = 1; i < Length; i++)
	{
		if (Dataset[i - 1] <= Dataset[i]) continue; // ���� �Ǿ��ִ� ���-> ��X

		value = Dataset[i];

		for (j = 0; j < i; j++)
		{
			if (Dataset[j] > value)
			{
				// memmove-> �޸��� ���� �̵� ���, �迭ó�� ���ӵ� ������ �ܹ��� �̵�
				// ���� �����Ͱ� �ű� ���ο� �޸� �ּ�, ���� �����Ͱ� �ִ� �ּ�, �̵���ų �������� ��
				// memcpy�� ���ο� ������ ����! vs. memmove�� �̵�!
				memmove(&Dataset[j + 1], &Dataset[j], sizeof(Dataset[0])*(i - j));
				Dataset[j] = value;
				break;
			}
		}
	}
}

int main(void)
{
	int Dataset[] = { 6,4,2,3,1,5 };
	int Length = sizeof(Dataset) / sizeof Dataset[0];

	InsertionSort(Dataset, Length);

	for (int i = 0; i < Length; i++)
		printf("%d ", Dataset[i]);
	printf("\n");
	return 0;
}
#include <stdio.h>

void BubbleSort(int Dataset[], int Length)
{
	int i, j, tmp = 0;

	for (i = 0; i < Length - 1; i++)
	{
		for (j = 0; j < Length - 1 - i; j++)
		{
			if (Dataset[j] > Dataset[j + 1])
			{
				tmp = Dataset[j];
				Dataset[j] = Dataset[j + 1];
				Dataset[j + 1] = tmp;
			}
		}
	}
}

int main(void)
{
	int Dataset[] = { 6,4,2,3,1,5 };
	int Length = sizeof(Dataset) / sizeof(Dataset[0]);
	BubbleSort(Dataset, Length);

	for (int i = 0; i < Length; i++)
		printf("%d ", Dataset[i]);
	printf("\n");

	//printf("%d %d\n", sizeof(Dataset), sizeof(Dataset[0]));
	return 0;
}
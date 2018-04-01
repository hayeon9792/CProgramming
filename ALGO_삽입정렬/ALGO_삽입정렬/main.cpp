#include <stdio.h>
#include <string.h>
/*
삽입정렬
비교대상을 2개~N개로 늘려가며 2,3,4,...,N번째 값의 자리를 찾아 나감
5 1 6 4 2 3
(5 1) 6 4 2 3 -> (1 5) 6 4 2 3
(1 5 6) 4 2 3 -> (1 5 6) 4 2 3
(1 5 6 4) 2 3 -> (1 4 5 6) 2 3
...

버블 정렬은 정렬된 데이터에 대해서도 무조건 N(N-1)/2 번 반복
삽입 정렬은 최선(정렬된 데이터)-> N-1 /최악-> N(N-1)/2 
따라서, 똑같은 O(N^2)이지만, 삽입정렬>버블 정렬 
*/
void InsertionSort(int Dataset[], int Length)
{
	int i, j, value = 0;

	for (i = 1; i < Length; i++)
	{
		if (Dataset[i - 1] <= Dataset[i]) continue; // 정렬 되어있는 경우-> 비교X

		value = Dataset[i];

		for (j = 0; j < i; j++)
		{
			if (Dataset[j] > value)
			{
				// memmove-> 메모리의 내용 이동 기능, 배열처럼 연속된 데이터 단번에 이동
				// 원본 데이터가 옮길 새로운 메모리 주소, 원본 데이터가 있는 주소, 이동시킬 데이터의 양
				// memcpy는 새로운 곳으로 복사! vs. memmove는 이동!
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
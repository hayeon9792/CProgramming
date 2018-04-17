#include <stdio.h>

int arr[5] = { 2,4,6,1,7 };

int main()
{
	int temp = 0;

	for (int i = 1; i <= 4; i++){

		for (int j = 0; j < 5 - i; j++){

			if (arr[j] > arr[j + 1]){

				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	} //정렬 종료

	for (int i = 0; i < 5; i++){

		printf("%d ", arr[i]);

	}

	printf("\n");

	return 0;
}
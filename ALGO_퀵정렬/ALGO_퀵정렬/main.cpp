//#include <stdio.h>
/*
분할 정복(Divide and Conquer) 기반
기준요소(Pivot)설정 방법-> 랜덤 값이 가장 좋지만, 값 선택 과정 중 성능 저하 발생
처음 데이터 집합 세개중 중간 값 선택, 아주 작은 비용 지출, but 최소값이나 최대값 선택 막을 수 있음

수색 섬멸: 두 명의 정찰병
한 명은 왼쪽->오른쪽으로 pivot보다 큰 값 찾고, 한 명은 오른쪽->왼쪽으로 pivot보다 작은 값 찾음
그리고 두 정찰병이 찾은 두 값을 교환
둘이 만날 때까지 위의 과정 반복, 둘이 만나면 pivot을 왼쪽데이터 집합의 마지막 요소와 교환하고 종료

성능 분석 요소 -> 재귀 호출 깊이, 데이터 집합 나누기 위해 비교하는 횟수

- 이상적인 경우 퀵 정렬의 비교 횟수 = 재귀 호출의 깊이 * 각 재귀 호출 단계에서의 비교 횟수 = log2n * n = nlog2n
- 최악의 경우 = 데이터가 정렬된 상태 = 재귀 호출의 깊이(n-1) * 각 재귀 호출 단계에서의 비교 횟수((n-1)+(n-2)+(n-3)+...+1) = n(n-1)/2
- 평균 = 1.39nlog2n = O(nlog2n)
*/
/*
void Swap(int* A, int* B) //주소값을 포인터로 받아옴
{
	int tmp = *A; // 주소값의 포인터를 저장 (=값)
	*A = *B;
	*B = tmp;
}

int Partition(int Dataset[], int Left, int Right)
{
	int First = Left;
	int Pivot = Dataset[First];

	++Left;
	while (Left <= Right)
	{
		while (Dataset[Left] <= Pivot && Left < Right)
			++Left;
		while (Dataset[Right] > Pivot&& Left <= Right)
			--Right;

		if (Left < Right)
			Swap(&Dataset[Left], &Dataset[Right]);
		else
			break;
	}

	Swap(&Dataset[First], &Dataset[Right]);
	return Right; // 가운데 idx 리턴
}

void qSort(int Dataset[], int Left, int Right)
{
	if (Left < Right)
	{
		int idx = Partition(Dataset, Left, Right); // 기준!

		qSort(Dataset, Left, idx - 1);
		qSort(Dataset, idx + 1, Right);
	}
}

int main(void)
{
	int Dataset[] = { 6,4,2,3,1,5 };
	int Length = sizeof Dataset / sizeof Dataset[0];
	
	qSort(Dataset, 0, Length - 1);
	for (int i = 0; i < Length; i++)
		printf("%d ", Dataset[i]);
	printf("\n");
	return 0;
}*/
//#include <stdio.h>
/*
���� ����(Divide and Conquer) ���
���ؿ��(Pivot)���� ���-> ���� ���� ���� ������, �� ���� ���� �� ���� ���� �߻�
ó�� ������ ���� ������ �߰� �� ����, ���� ���� ��� ����, but �ּҰ��̳� �ִ밪 ���� ���� �� ����

���� ����: �� ���� ������
�� ���� ����->���������� pivot���� ū �� ã��, �� ���� ������->�������� pivot���� ���� �� ã��
�׸��� �� �������� ã�� �� ���� ��ȯ
���� ���� ������ ���� ���� �ݺ�, ���� ������ pivot�� ���ʵ����� ������ ������ ��ҿ� ��ȯ�ϰ� ����

���� �м� ��� -> ��� ȣ�� ����, ������ ���� ������ ���� ���ϴ� Ƚ��

- �̻����� ��� �� ������ �� Ƚ�� = ��� ȣ���� ���� * �� ��� ȣ�� �ܰ迡���� �� Ƚ�� = log2n * n = nlog2n
- �־��� ��� = �����Ͱ� ���ĵ� ���� = ��� ȣ���� ����(n-1) * �� ��� ȣ�� �ܰ迡���� �� Ƚ��((n-1)+(n-2)+(n-3)+...+1) = n(n-1)/2
- ��� = 1.39nlog2n = O(nlog2n)
*/
/*
void Swap(int* A, int* B) //�ּҰ��� �����ͷ� �޾ƿ�
{
	int tmp = *A; // �ּҰ��� �����͸� ���� (=��)
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
	return Right; // ��� idx ����
}

void qSort(int Dataset[], int Left, int Right)
{
	if (Left < Right)
	{
		int idx = Partition(Dataset, Left, Right); // ����!

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
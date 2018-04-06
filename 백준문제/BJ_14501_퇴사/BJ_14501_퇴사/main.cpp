#include <stdio.h>

int N, res;
int T[16], P[16];

void solve(int n, int cost)
{
	if (n == N + 1 && cost > res) res = cost; //������ �� ��쿡! ����
	if (n > N) return;

	solve(n + T[n], cost + P[n]); //���� �ϴ� ���
	solve(n + 1, cost); //���� ���ϴ� ���
}

int main()
{
	//freopen("input.txt", "r", stdin);

	//int testcase;
	//scanf("%d", &testcase);
	//for (int tc = 1; tc <= testcase; tc++)
	{
		scanf("%d", &N); //N�� �ε��� ������ �ִ� �κ�����, but N�� T[i]��ŭ �پ�
		for (int i = 1; i <= N; i++)
			scanf("%d %d", &T[i], &P[i]);

		// 1�Ϻ��� N�ϱ��� ����
		res = 0;
		solve(1, 0);

		printf("\%d\n",\ res);
		//printf("#%d %d\n", tc, res);
	//}
	return 0;
}
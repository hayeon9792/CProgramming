#include <stdio.h>

int N, res;
int T[16], P[16];

void solve(int n, int cost)
{
	if (n == N + 1 && cost > res) res = cost; //끝까지 간 경우에! 종료
	if (n > N) return;

	solve(n + T[n], cost + P[n]); //선택 하는 경우
	solve(n + 1, cost); //선택 안하는 경우
}

int main()
{
	//freopen("input.txt", "r", stdin);

	//int testcase;
	//scanf("%d", &testcase);
	//for (int tc = 1; tc <= testcase; tc++)
	{
		scanf("%d", &N); //N개 인덱스 까지의 최대 부분집합, but N은 T[i]만큼 뛰어
		for (int i = 1; i <= N; i++)
			scanf("%d %d", &T[i], &P[i]);

		// 1일부터 N일까지 시작
		res = 0;
		solve(1, 0);

		printf("\%d\n",\ res);
		//printf("#%d %d\n", tc, res);
	//}
	return 0;
}
#include <iostream>
using namespace std;

int a[500][500];
bool c[500][500];
long long d[500][500];

int n;

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };


void pnt(int num)
{
	printf("%d \n", num);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(num==1)printf("%d ", a[i][j]);
			else if (num == 2)printf("%lld ", d[i][j]);
			else if (num == 3)printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

long long dfs(int x, int y) {
	long long result = 0;

	if (x == n - 1 && y == n - 1) { //도착 -> 1
		return 1;
	}
	if (a[x][y] == 0) {
		return 0;
	}
	if (d[x][y] != -1) { //아직 방문 X
		return d[x][y];
	}
	c[x][y] = true;
	int temp = a[x][y];
	if (x + temp<n) {
		result += dfs(x + temp, y);
	}

	if (y + temp<n) {
		result += dfs(x, y + temp);
	}

	d[x][y] = result;
	c[x][y] = false;


	return result;
}



int main() {
	cin >> n;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
		}
	}

	long long result = dfs(0, 0);
	cout << result << endl;

	return 0;
}


/*
#include <stdio.h>

typedef long long ll;
ll res, N, map[100][100];


void dfs(ll curi, ll curj)
{

	if (curi < 0 || curj < 0 || curi >= N || curj >= N) return;

	if (map[curi][curj] == 0)
	{
		res++;
		return;
	}

	// 오른쪽
	if (curj + map[curi][curj] < N)
		dfs(curi, curj + map[curi][curj]);
	// 아래쪽
	if (curi + map[curi][curj] < N)
		dfs(curi + map[curi][curj], curj);
}

int main()
{
	scanf("%lld", &N);
	for (ll i = 0; i < N; i++)
		for (ll j = 0; j < N; j++)
			scanf("%lld", &map[i][j]);

	res = 0;
	dfs(0, 0);
	printf("%lld\n", res);
	return 0;
}
*/


#include <stdio.h>
#include <string.h>

typedef struct _info {
	int x, y;
}info;

info q[10001];
int res, N, M, map[300][300], buf[300][300]; // ������ �ִ� ���� �ִ� 10000��
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[300][300];

//melt -> map�� ���� buf�� �ִ� �ֵ��� ����. �� ���̰� ���� map<=buf ... �ݺ�
void melt()
{
	int front = 0, rear = 0;
	
	// ������ ť�� �־�!
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] != 0)
			{
				q[rear].x = i;
				q[rear].y = j;
				rear++;
			}

	// �쿩!
	while (front != rear)
	{
		int cx, cy;
		cx = q[front].x;
		cy = q[front].y;
		front++;

		int cnt = 0;

		for (int d = 0; d < 4; d++)
		{
			int nx, ny;
			nx = cx + dx[d];
			ny = cy + dy[d];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] != 0) continue;
			if (map[nx][ny] == 0) cnt++;
		}

		buf[cx][cy] -= cnt;
		if (buf[cx][cy] < 0)buf[cx][cy] = 0;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] = buf[i][j];
}

void numbering(int x, int y)
{
	int front = 0, rear = 0;

	q[rear].x = x;
	q[rear].y = y;
	rear++;

	while (front != rear)
	{
		int cx, cy;
		cx = q[front].x;
		cy = q[front].y;
		front++;


		for (int d = 0; d < 4; d++)
		{
			int nx, ny;
			nx = cx + dx[d];
			ny = cy + dy[d];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M 
				|| map[nx][ny] == 0 || visit[nx][ny]) continue;

			visit[nx][ny] = true;

			q[rear].x = nx;
			q[rear].y = ny;
			rear++;
		}
	}
}

//numbering -> ������ȣ���̱�~ // ���ϰ� ������ res=0;
int solve()
{
	int cnt, year = 0;
	
	while (1)
	{
		cnt = 0;

		memset(visit, false, sizeof(visit));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0 || visit[i][j]) continue;
				cnt++;
				if (cnt == 2) return year;
				numbering(i, j);
			}
		}

		//���� cnt==1�̸� ������ �ϳ� -> ������ , cnt==0�̸� �� ������
		if (cnt == 0) return 0;
		else if (cnt == 1) melt();
		else return -1;

		year++;
	}

	return -1;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			buf[i][j] = map[i][j];
		}
	
	int res = solve();
	printf("%d\n", res);

	return 0;
}
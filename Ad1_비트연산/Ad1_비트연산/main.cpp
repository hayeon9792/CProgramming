#include <stdio.h>
/*
void BitPrint(int i)
{
	for (int j = 7; j >= 0; j--) // 1Byte 출력
	{
		// if(i&(1<<j)==1) 이나 if(i&(1<<j)==true) 이런거 안됨
		if (i&(1 << j)) printf("1");
		else printf("0");
		//printf("%d", (i >> j) & 1); // j=7이면 7번 오른쪽으로 보내므로 최상위비트만 남음
	}
	printf(" ");
}

int main(void)
{
	BitPrint(14);
	printf("\n\n");

	char *p;
	char a = 0x10;
	int x = 0x01020304;

	printf("%d = ", a);
	p = &a;
	BitPrint(*p); // 16진수->2진수
	printf("\n\n");

	printf("0%X = ", x);
	p = (char *)&x; // 정수형 변수 x의 시작 주소를 문자형 포인터 변수 p에 저장
	for (int i = 0; i < 4; i++) // char* -> 4바이트, 1Byte 씩 출력
		BitPrint(*p++); //증감 연산자가 무조건 우선, *p++ = *(p++) = *(p+i)

	printf("\n\n");
	return 0;
}*/

void ce(int *n)
{
	//1) x값=32비트 중, 24비트 왼쪽으로 보내면 맨 마지막 8비트 (4,0,0,0), 즉 4번째 바이트만 남는다.
	//2) 8비트 왼쪽으로 보내면 2,3,4,0이 되는데, 거기에 0xff0000(1,0,0)을 곱했기 때문에 3만 남는다
	//3) 8비트 오른쪽으로 보내면 0,1,2,3이 되는데, 거기에 0xff00(1,0)을 곱했기 때문에 2만 남는다.
	//4) 24비트 오른쪽으로 보내면 0,0,0,1 이므로 1번째 바이트만 남는다.
	//5) 위의 4과정을 다 더하면 4,3,2,1
	*n = (*n << 24) | ((*n << 8) & 0xff0000) | ((*n >> 8) & 0xff00) | (*n >> 24);
}

void main(void)
{
	int x = 0x01020304;
	int s = sizeof(x);
	char *p = (char*) &x;
	printf("x = %d%d%d%d\n", p[0], p[1], p[2], p[3]);
	ce(&x);
	printf("x = %d%d%d%d\n", p[0], p[1], p[2], p[3]);
}
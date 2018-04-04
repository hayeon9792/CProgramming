#include <stdio.h>

int bitmask, M;
char ins[7];

int main(void)
{
	bitmask = 0;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int x;
		scanf("%s", ins);
		scanf("%d", &x);
		x -= 1;
		if (ins[0] == 'a' && ins[1] == 'd')
		{
			if (!(bitmask&(1 << x))) bitmask |= (1 << x);
		}
		else if (ins[0] == 'r')
		{
			if ((bitmask & (1 << x))) bitmask &= ~(1 << x);
		}
		else if (ins[0] == 'c')
		{
			if (bitmask&(1 << x)) printf("1\n");
			else printf("0\n");
		}
		else if (ins[0] == 't')
		{
			if (bitmask&(1 << x)) bitmask &= ~(1 << x);
			else bitmask |= (1 << x);
		}
		else if (ins[0] == 'a' && ins[1] == 'l') bitmask = (1 << 20) - 1;
		else if (ins[0] == 'e') bitmask = 0;
	}
	return 0;
}


/*
int bitmask, M;
char ins[7];

void bitprint()
{
	for (int i = 20-1; i >= 0; i--)
	{
		if( bitmask&(1 << i)) printf("1");
		else printf("0");
	}
	printf("\n");
}

void add(int x)
{
	if (!(bitmask&(1 << x))) bitmask |= (1 << x);
	//if (!(1 & (check >> x))) check |= (1 << x);
}

void remove(int x)
{
	if ((bitmask & (1<< x))) bitmask &= ~(1 << x);
}

int check(int x)
{
	if (bitmask&(1 << x)) return 1;
	else return 0;
}

void toggle(int x)
{
	if (check(x)) remove(x);
	else add(x);
}

void all()
{
	bitmask = (1 << 20) - 1;
}

void empty()
{
	bitmask = 0;
}


int main(void)
{
	bitmask = 0;
	scanf("%d", &M);
	bitprint();
	for (int i = 0; i < M; i++)
	{
		int x;
		scanf("%s", ins);
		scanf("%d", &x);
		x -= 1;
		if (ins[0] == 'a' && ins[1]=='d') if (!(bitmask&(1 << x))) bitmask |= (1 << x);
		else if (ins[0] == 'r') if ((bitmask & (1 << x))) bitmask &= ~(1 << x);
		else if (ins[0] == 'c')
		{
			if (bitmask&(1 << x)) printf("1\n");
			else printf("0\n");
		}
		else if (ins[0] == 't')
		{
			if (bitmask&(1 << x)) bitmask &= ~(1 << x);
			else bitmask |= (1 << x);
		}
		else if (ins[0]=='a' && ins[1]=='l') bitmask = (1 << 20) - 1;
		else if (ins[0] == 'e') bitmask = 0;
		bitprint();
	}
	return 0;
}*/
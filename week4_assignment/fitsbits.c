#include <stdio.h>


int fitsBits(int x , int n)
{
	int shift = 32 + (~n + 1);
	return !(((x << shift) >> shift) ^ x);
}

int main()
{
	printf("%d\n", fitsBits(-4,3));
	return 0;
}

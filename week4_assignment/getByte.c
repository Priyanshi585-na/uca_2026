#include <stdio.h>

int getByte(int x, int n)
{
	return (x >> (n << 3)) & 0xFF;
}

int main()
{
	printf("%d\n", getByte(0x12345678, 1));

	return 0;
}

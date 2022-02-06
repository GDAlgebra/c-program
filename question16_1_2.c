/*运算符的优先级是+,-高于<<,>>高于&|~*/
#include<stdio.h>

int countbit(unsigned int x)
{
	int j = 0;
	unsigned int mask = 0x00000001;
	for (int i = 0; i < 31; i++)
	{
		if ((x & mask) >> i == 1)
		{
			j++;
		}
		mask = mask * 2;
	}
	return j;
}

unsigned int multiply(unsigned int x, unsigned int y)
{
	unsigned int mask = 0x00000001, result=0x00000000;
	for (int i = 0; i < 31; i++)
	{
		if ((y & mask) >> i == 1)
		{
			result = result + (x << i);
		}
		mask << 1;
	}
	return result;
}

unsigned int rotate_right(unsigned int x)
{
	return (x >> 1) + ((x & 0x00000001) << 31);
}

int main(void)
{
	unsigned int x = 0xad734f59;
	printf("%d, %x\n", countbit(x),x);
	printf("%x\n", multiply(0x00000015,0x00000005));
	printf("%x\n", rotate_right(0x00000001));
	return 0;
}

#include<stdio.h>

void diamond(int x, char y)
{
	if (x % 2 != 1 || x < 0)
	{
		printf("the first parameter must be a positive odd!");
		exit(1);
	}
	for (int i = 0; i < x / 2; i++)//top half
	{
		for (int j = 0; j < x; j++)
		{
			if (j >= x / 2 - i && j <= x / 2 + i)
				printf("%c  ", y);
			else
				printf("   ");
		}
		printf("\n");
	}
	for (int i = x/2; i < x; i++)//bottom half
	{
		for (int j = 0; j < x; j++)
		{
			if (j >= x / 2 - (x - i - 1) && j <= x / 2 + (x - i - 1))
				printf("%c  ", y);
			else
				printf("   ");
		}
		printf("\n");
	}
}

int main(void)
{
	diamond(11, 'x');
	return 0;
}
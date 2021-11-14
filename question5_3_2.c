#include<stdio.h>
int Fibonacci(int x)
{
	int y = x;
	if (x == 0 || x == 1)
		return 1;
	else
		return Fibonacci(y - 1) + Fibonacci(y - 2);
}
int main(void)
{
	printf("%d", Fibonacci(15));
	return 0;
}
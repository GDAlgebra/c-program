//find prime in 100 without using break and continue function

#include <stdio.h>

int is_prime(int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	if (i == n)
		return 1;
}

int main(void)
{
	int i;
	for (i = 1; i <= 100; i++) {
		if (1-!is_prime(i))
		printf("%d\n", i);
	}
	return 0;
}
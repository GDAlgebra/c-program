#include<stdio.h>
#include <stdlib.h>
#define N 200

int a[N];

void gen_random(int upper_bound)
{
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % upper_bound;
}

void print_random()
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
}


int main(void)
{
	gen_random(10);
	int i, histogram[10] = { 0 };
	for (i = 0; i < N; i++)
		histogram[a[i]]++;
	printf("0 1 2 3 4 5 6 7 8 9 \n");
	int print_time = 0;
	while (print_time<N)
	{
		for ( int j = 0; j < 10; j++)
		{
			if (histogram[j] > 0)
			{
				printf("* ");
				print_time++;
				histogram[j]--;
			}
			else
				printf("  ");
		}
		printf("\n");

	}

	return 0;
}
#include<stdio.h>

/* 
 * comment 1
 * main: generate some simple output 
 */

int main(void)
{
	int x = 17, n = 4, result;
	result = (x + n - 1)/ n; /*if x/n is not a integer, then x-1/n=x/n.*/ 
	printf("%d divide %d is %d\n",x,n,result );
	return 0;
}
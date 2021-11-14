#include<stdio.h>

void print_ud_td(int x)
{
	int unitdigit, tendigit;
	unitdigit = x - x / 10 * 10;/*expression to show unit digit of an integer*/
	tendigit = (x - x / 100 * 100) / 10;/*expression to show ten digit of an integer*/
	printf("the tendigit of x is %d,the unitdigit of x is %d", tendigit, unitdigit);
}
int main(void)
{
	print_ud_td(126);
	return 0;
}
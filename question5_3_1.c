#include<stdio.h>

int Greatest_Common_Divisor(int x, int y)
{
	int xx=x, yy=y, gcd;
	if (x>y)
	{
		yy = x;
		xx = y;
	}//make sure x<=y
	if (yy % xx == 0) {
		gcd = xx;
		return gcd;
	}
	else {
		gcd = Greatest_Common_Divisor(yy % xx, xx);
		return gcd;
	}
}
int main(void)
{

	printf("%d" ,Greatest_Common_Divisor(5,8) );
	return 0;
}

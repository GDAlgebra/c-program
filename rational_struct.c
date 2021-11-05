#include<stdio.h>
#include<math.h>

struct rational{
	int x, y;
};

struct rational make_rational(int a,int b)
{
	if (b == 0)
	{
		printf("The denominator can not be zero!");
		exit(1);
	}
	struct rational c;
	c.x = a;
	c.y = b;
	return c;
}

int Greatest_Common_Divisor(int x, int y)
{
	if (x == 0 || y == 0)
		return 0;//exclude 0
	int xx = abs(x), yy = abs(y), gcd;
	if (abs(x) > abs(y))
	{
		yy = abs(x);
		xx = abs(y);
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

void print_rational(struct rational a) 
{
	if (a.x == 0)
	{
		printf("0\n");
		return;
	}//exclude 0 in the numerator
	int gcd = Greatest_Common_Divisor(a.x, a.y), x1, x2, x11, x22;
	x1 = a.x / gcd; x2 = a.y / gcd;
	x11 = abs(x1); x22 = abs(x2);
	if (x11 % x22 == 0)
		printf("%d\n", x11 / x22);
	else
	{
		if ((x1 / x11 + x2 / x22) % 2)
			printf("-%d/%d\n", x11, x22);
		else
			printf("%d/%d\n", x11, x22);
	}//judge whether the rational is positive or negative
}

struct rational add_rational(struct rational a,struct rational b) 
{
	int x = a.x * b.y + b.x * a.y, y = a.y * b.y;
	return make_rational(x, y);
}

struct rational sub_rational(struct rational a, struct rational b)
{
	int x = a.x * b.y - b.x * a.y, y = a.y * b.y;
	return make_rational(x, y);
}

struct rational mul_rational(struct rational a, struct rational b)
{
	int x = a.x * b.x, y = a.y * b.y;
	return make_rational(x, y);
}

struct rational div_rational(struct rational a, struct rational b)
{
	if (b.x==0)
	{
		printf("can't divide 0!!");
		exit(1);
	}
	int x = a.x * b.y, y = a.y * b.x;
	return make_rational(x, y);
}

int main(void)
{
	struct rational a = make_rational(4, 8);/* a=1/8 */
	struct rational b = make_rational(-2, -8);/* b=-1/8 */
	print_rational(a);
	print_rational(b);
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));
	
	return 0;
}

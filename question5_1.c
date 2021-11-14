#include<stdio.h>
int is_leap_year(int year)
{
	if (year % 4 == 0 && year % 100 != 0) {
		printf("This year is a leap year\n");
		return 1;
	}else {
		if (year % 400 == 0) {
			printf("This year is a leap year\n");
			return 1;
		}
		else {
			printf("This year is not a leap year\n");
			return 0;
		}
	}
}
int main(void)
{
	is_leap_year(3);
	is_leap_year(4);
	is_leap_year(100);
	is_leap_year(400);
	return 0;
}
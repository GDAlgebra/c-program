#include<stdio.h>

void Quicksort(int a[8], int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int first = low;
	int last = high;
	int key = a[first];
	while (first < last)
	{
		while (first < last && a[last] >= key)    //����������һ����arr[left]С��ֵ
		{
			--last;
		}
		a[first] = a[last];
		while (first < last && a[first] <= key)    //����������һ����arr[left]Ҫ���ֵ
		{
			++first;
		}
		a[last] = a[first];

	}
	a[first] = key;
	Quicksort(a, low, first - 1);    //�����
	Quicksort(a, last + 1, high);    //���ұ�
}

int main(void)
{
	int a[8] = { 5,2,4,7,1,3,2,6 };
	Quicksort(a, 0, 7);
	for (int i = 0; i < 8; i++)
		printf("%d,", a[i]);
	return 0;
}
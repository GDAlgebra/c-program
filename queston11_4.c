/*��a[start..end]��ѡȡһ��pivotԪ�أ�����ѡa[start]Ϊpivot��;
��һ��ѭ�����ƶ�a[start..end]�����ݣ���a[start..end]�ֳ����룬
	ʹa[start..mid - 1]��pivotԪ��С��a[mid + 1..end]��pivotԪ�ش󣬶�a[mid]����pivotԪ��;*/
#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int partition(int start, int end)
{
	int pivot = a[start], trans, mid=start;
	for (int i = 1; i <= end-start; i++)
	{
		if (a[start+i]<pivot)
		{
			trans = a[start + i];
			for ( int j = 0; j < start+i-mid; j++)
			{
				a[start + i - j] = a[start + i - j - 1];
			}
			a[mid] = trans;
			mid++;
		}
	}
	return mid;
}

void quicksort(int start, int end)
{
	int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid - 1);
		quicksort(mid + 1, end);
	}
}

int main(void)
{
	quicksort(0, 7);
	for (int i = 0; i < LEN; i++)
		printf("%d,", a[i]);
	return 0;
}
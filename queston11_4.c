/*从a[start..end]中选取一个pivot元素（比如选a[start]为pivot）;
在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
	使a[start..mid - 1]比pivot元素小，a[mid + 1..end]比pivot元素大，而a[mid]就是pivot元素;*/
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
// This is not the correct code for quicksort, the correct code is as followed.
int* Quicksort(int* array, int arraysize) {
    if (arraysize < 1) {
        return array;
    }
    int* start = array, * end = array + arraysize - 1, mid = *array, temp = *(array + 1);
    while (start != end) {
        if (temp < mid) {
            *start = temp;
            start++;
            temp = *(start + 1);
        }
        else {
            *start = temp;
            temp = *end;
            *end = *start;
            end--;
        }
    }
    *start = mid;
    Quicksort(array, start - array);
    Quicksort(array + (start - array) + 1, arraysize - (start - array) - 1);
}

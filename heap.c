#include<stdio.h>
#include<stdlib.h>

struct HEAP
{
	double* heap;
	int heap_size;
};


double parent(struct HEAP h, int i) {
	if (i == 1) {
		printf("No parent!");
		exit(1);
	}
	return *(h.heap + i / 2 - 1);
}

double left(struct HEAP h, int i) {
/*	if (2 * i > h.heap_size) {
		printf("No left!");
		exit(1);
	}
    */
	return *(h.heap + i * 2 - 1);
}

double right(struct HEAP h, int i) {
/*	if (2 * i + 1 >= h.heap_size) {
		printf("No right!");
		exit(1);
	}
	*/
	return *(h.heap + i * 2);
}

void max_heapify(struct HEAP h, int i) {
	if (i > h.heap_size / 2)
		return;
	double l = left(h,i), r= right(h,i), largestkey = *(h.heap + i - 1);
	int largest = i;
	if (2 * i <= h.heap_size && l > *(h.heap + i - 1)) {
		largestkey = l;
		largest = 2 * i;
	}
	if (2 * i + 1 <= h.heap_size && r > largestkey) {
		largestkey = r;
		largest = 2 * i + 1;
	}
	if (largest != i) {
		*(h.heap + largest - 1) = *(h.heap + i - 1);
		*(h.heap + i - 1) = largestkey;
		max_heapify(h, largest);
	}
	return;
}

struct HEAP build_max_heap(double* array, int arraysize) {
	struct HEAP h;
	h.heap = (double*)malloc(sizeof(double) * arraysize);
	for (int i = 0; i < arraysize; i++) {
		*(h.heap + i) = *(array + i);
	}
	h.heap_size = arraysize;
	for (int i = arraysize / 2; i > 1; i--) {
		max_heapify(h, 1);
	}
	return h;
}

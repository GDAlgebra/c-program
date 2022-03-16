// Introduction to Algorithms §8.2
void counting_sort(int a[], int b[], int range, int numsize) {
	int* c = (int*)malloc(sizeof(int) * (range + 1));
	for (int i = 0; i < range + 1; i++)
		*(c + i) = 0;
	for (int i = 0; i < numsize; i++) 
		*(c + *(a + i)) = *(c + *(a + i)) + 1;
	//c[i] now contains the number of elements equal to i
	for (int i = 1; i < range + 1; i++)
		*(c + i) = *(c + i) + *(c + i - 1);
	//c[i] now contains the number of elements less than or equal to i
	for (int i = numsize - 1; i >= 0; i--) {
		*(b + *(c + *(a + i)) - 1) = *(a + i);
		*(c + *(a + i)) = *(c + *(a + i)) - 1;
	}
	free(c);
}

int main(void) {
	int a[11] = { 6,0,2,0,1,3,4,6,1,3,2 }, b[11] = {0};
	counting_sort(a, b, 6, 11);
	return 0;
}

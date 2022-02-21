/**
 * question: given an array, find the nonempty, contiguous subarray of A whose values have the largest sum.
 * The time complexity of your code should be O(nlogn).
 */
int Find_Crossing_Subarray(int* array, int arraysize, int mid) {
    int left_sum = -_CRT_INT_MAX, sum = 0;
    for (int i = mid; i > 0; i--) {
        sum = sum + *(array + i - 1);
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    int right_sum = -_CRT_INT_MAX;
    sum = 0;
    for (int i = mid + 1; i <= arraysize; i++) {
        sum = sum + *(array + i - 1);
        if (sum > right_sum) {
            right_sum = sum;
        }
    }
    return left_sum + right_sum;
}

int Find_Maximum_Subarray(int* array, int arraysize) {
    if (arraysize == 1)
        return *array;
    int mid = arraysize / 2;
    int leftsum = Find_Maximum_Subarray(array, mid);
    int rightsum = Find_Maximum_Subarray(array + mid, arraysize - mid);
    int crosssum = Find_Crossing_Subarray(array, arraysize, mid);
    if (leftsum >= rightsum && leftsum >= crosssum)
        return leftsum;
    else {
        if (rightsum >= leftsum && rightsum >= crosssum)
            return rightsum;
        else
            return crosssum;
    }
}
 

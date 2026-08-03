#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[right]);
    return i;
}

void quickSelect(int arr[], int left, int right, int k) {
    if (left >= right)
        return;

    
    int pivotIndex = left + rand() % (right - left + 1);
    swap(&arr[pivotIndex], &arr[right]);

    int p = partition(arr, left, right);

    if (p == k)
        return;
    else if (p > k)
        quickSelect(arr, left, p - 1, k);
    else
        quickSelect(arr, p + 1, right, k);
}

int main() {
    srand(time(NULL));

    int arr[] = {10, 4, 5, 8, 6, 11, 26, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 4;

    if (K <= 0 || K > n) {
        return 1;
    }

    clock_t start = clock();
    
    quickSelect(arr, 0, n - 1, K - 1);
    
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("%d %.6f\n", n, elapsed);
    
    return 0;
}

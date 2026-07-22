#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int left, int mid, int right) {
    long long count = 0;

    int n = right - left + 1;
    int *temp = (int *)malloc(n * sizeof(int));

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = 0; i < n; i++)
        arr[left + i] = temp[i];

    free(temp);

    return count;
}

long long mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    long long count = 0;

    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += merge(arr, left, mid, right);

    return count;
}

int main() {
    int arr[100000];
    int n = 0;

    while (scanf("%d", &arr[n]) == 1)
        n++;

    printf("%lld\n", mergeSort(arr, 0, n - 1));

    return 0;
}

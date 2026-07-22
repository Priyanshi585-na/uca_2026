#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Node;

void merge(Node arr[], int left, int mid, int right, int ans[]) {
    int n = right - left + 1;
    Node *temp = (Node *)malloc(n * sizeof(Node));

    int i = left;
    int j = mid + 1;
    int k = 0;

    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            ans[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        ans[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < n; i++)
        arr[left + i] = temp[i];

    free(temp);
}

void mergeSort(Node arr[], int left, int right, int ans[]) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, ans);
    mergeSort(arr, mid + 1, right, ans);

    merge(arr, left, mid, right, ans);
}

int main() {
    int nums[100000];
    int n = 0;

    while (scanf("%d", &nums[n]) == 1)
        n++;

    Node arr[100000];
    int ans[100000] = {0};

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, n - 1, ans);

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int left, int mid, int right)
{
	long long count = 0;

	int j = mid + 1;
	for(int i = left; i <=mid ; i++){
		while(j <= right && (long long)arr[i] > 2LL * arr[j]) j++;
		count += j - (mid+1);
	}	


	int n = right - left + 1;
	int *temp = (int *)malloc(n * sizeof(int));

	int i = left, k = 0;
	j = mid + 1;

	while (i <= mid && j<= right)
	{
		if(arr[i] <= arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}

	while (i <= mid) temp[k++] = arr[i++];
	while (j <= right) temp[k++] = arr[j++];

	for (int i = 0 ; i < n ; i++) arr[left + i] = temp[i];

	free(temp);
	return count;
}


long long mergeSort(int arr[], int left, int right)
{
	if (left >= right) return 0;

	int mid = left + (right - left) / 2;

	long long count = 0;

	count += mergeSort(arr, left, mid);
	count += mergeSort(arr, mid+1, right);
	count += merge(arr, left, mid, right);

	return count;
}

int main(){
	int arr[100000];
	int n = 0;
	while (scanf("%d", &arr[n]) == 1) n++;

	printf("%lld\n", mergeSort(arr, 0 , n-1));

	return 0;
}

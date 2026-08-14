#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t size)
{
	void *temp = malloc(size);

	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);

	free(temp);
}


void heapify(void *arr, int n, int i, size_t size, int(*compare)(const void *, const void *))
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	char *base = (char *)arr;

	if (left < n && compare(base + left*size, base + largest * size) > 0)
	{
		largest = left;
	}

	if (right < n && compare(base + right * size, base + largest * size) > 0)
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(base + i * size, base + largest * size, size);
		heapify(arr, n , largest, size, compare);
	}
}


void heapSort(void *arr, int n, size_t size, int(*compare)(const void*, const void*))
{
	for (int i = n/2-1 ; i >= 0 ; i--)
	{
		heapify(arr, n, i, size, compare);
	}

	for(int i = n-1; i > 0 ; i--)
	{
		char *base = (char *)arr;

		swap(base, base + i * size, size);
		heapify(arr, i, 0, size, compare);
	}
}

int compareInt(const void *a, const void *b)
{
	int x = *(const int *)a;
	int y = *(const int *)b;

	return x-y;
}

int compareFloat(const void *a, const void *b)
{
	float x = *(const float *)a;
	float y = *(const float *)b;

	if(x > y) return 1;
	if(x < y) return -1;
	return 0;
}

typedef struct
{
	char name[20];
	int age;
} Student;

int compareStudent(const void *a, const void *b)
{
	Student *s1 = (Student *)a;
	Student *s2 = (Student *)b;

	return s1->age - s2->age;
}

int main()
{
	int nums[] = {12,5,7,8,4,5,2};
	int n = sizeof(nums)/sizeof(nums[0]);

	heapSort(nums, n, sizeof(n), compareInt);

	for (int i = 0 ; i < n ; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	Student students[] = {
		{"Hezal", 20},
		{"Vedanshi",19},
		{"Prarthna", 19},
		{"Naman", 21}
	};

	int m = sizeof(students)/sizeof(students[0]);

	heapSort(students, m, sizeof(Student), compareStudent);

	for (int i = 0; i < m ; i++)
	{
		printf("%s %d\n", students[i].name, students[i].age);
	}

	return 0;
}

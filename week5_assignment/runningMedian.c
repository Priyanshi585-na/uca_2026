#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->arr = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



void maxHeapifyUp(Heap* h, int i) {
    while(i > 0) {
        int parent = (i - 1) / 2;
        if(h->arr[parent] >= h->arr[i]) break;
        swap(&h->arr[parent], &h->arr[i]);
        i = parent;
    }
}

void maxHeapifyDown(Heap* h, int i) {
    while(1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if(left < h->size && h->arr[left] > h->arr[largest])
            largest = left;
        if(right < h->size && h->arr[right] > h->arr[largest])
            largest = right;

        if(largest == i) break;

        swap(&h->arr[i], &h->arr[largest]);
        i = largest;
    }
}

void insertMaxHeap(Heap* h, int val) {
    h->arr[h->size] = val;
    maxHeapifyUp(h, h->size);
    h->size++;
}

int extractMax(Heap* h) {
    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    maxHeapifyDown(h, 0);
    return root;
}

int getMax(Heap* h) {
    return h->arr[0];
}


void minHeapifyUp(Heap* h, int i) {
    while(i > 0) {
        int parent = (i - 1) / 2;
        if(h->arr[parent] <= h->arr[i]) break;
        swap(&h->arr[parent], &h->arr[i]);
        i = parent;
    }
}


void minHeapifyDown(Heap* h, int i) {
    while(1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < h->size && h->arr[left] < h->arr[smallest])
            smallest = left;
        if(right < h->size && h->arr[right] < h->arr[smallest])
            smallest = right;

        if(smallest == i) break;

        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }
}

void insertMinHeap(Heap* h, int val) {
    h->arr[h->size] = val;
    minHeapifyUp(h, h->size);
    h->size++;
}


int extractMin(Heap* h) {
    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    minHeapifyDown(h, 0);
    return root;
}

int getMin(Heap* h) {
    return h->arr[0];
}


typedef struct {
    Heap* maxHeap; 
    Heap* minHeap; 
} MedianFinder;

MedianFinder* createMedianFinder(int capacity) {
    MedianFinder* mf = (MedianFinder*)malloc(sizeof(MedianFinder));
    mf->maxHeap = createHeap(capacity);
    mf->minHeap = createHeap(capacity);
    return mf;
}

void balanceHeaps(MedianFinder* mf) {
    if(mf->maxHeap->size > mf->minHeap->size + 1) {
        int val = extractMax(mf->maxHeap);
        insertMinHeap(mf->minHeap, val);
    }
    else if(mf->minHeap->size > mf->maxHeap->size + 1) {
        int val = extractMin(mf->minHeap);
        insertMaxHeap(mf->maxHeap, val);
    }
}

void insert(MedianFinder* mf, int num) {
    if(mf->maxHeap->size == 0 || num <= getMax(mf->maxHeap)) {
        insertMaxHeap(mf->maxHeap, num);
    } else {
        insertMinHeap(mf->minHeap, num);
    }

    balanceHeaps(mf);
}


double getMedian(MedianFinder* mf) {
    if(mf->maxHeap->size == mf->minHeap->size) {
        return (getMax(mf->maxHeap) + getMin(mf->minHeap)) / 2.0;
    }
    else if(mf->maxHeap->size > mf->minHeap->size) {
        return getMax(mf->maxHeap);
    }
    else {
        return getMin(mf->minHeap);
    }
}

int main() {
    MedianFinder* mf = createMedianFinder(100);

    int stream[] = {5, 15, 1, 3};
    int n = 4;

    for(int i = 0; i < n; i++) {
        insert(mf, stream[i]);
        printf("Inserted: %d, Median: %.2f\n", stream[i], getMedian(mf));
    }

    return 0;
}

// Problem: Given meeting intervals (start, end), find the minimum number of rooms required.


#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int start;
    int end;
} Interval;

typedef struct {
    int *arr;
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *heap, int i) {
    while (i > 0 && heap->arr[(i - 1) / 2] > heap->arr[i]) {
        swap(&heap->arr[(i - 1) / 2], &heap->arr[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(MinHeap *heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insertHeap(MinHeap *heap, int val) {
    heap->arr[heap->size++] = val;
    heapifyUp(heap, heap->size - 1);
}

int extractMin(MinHeap *heap) {
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

int minMeetingRooms(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), compare);

    MinHeap heap;
    heap.arr = (int *)malloc(n * sizeof(int));
    heap.size = 0;

    insertHeap(&heap, arr[0].end);

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= heap.arr[0]) {
            extractMin(&heap);
        }
        insertHeap(&heap, arr[i].end);
    }

    return heap.size;
}

int main() {
    Interval arr[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", minMeetingRooms(arr, n));
    return 0;
}

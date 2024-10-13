#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;
    int list;
    int index;
} Element;

typedef struct {
    Element* array;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->array = (Element*)malloc(capacity * sizeof(Element));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left].value < heap->array[smallest].value)
        smallest = left;

    if (right < heap->size && heap->array[right].value < heap->array[smallest].value)
        smallest = right;

    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

void insert(MinHeap* heap, Element element) {
    if (heap->size == heap->capacity) {
        printf("Heap is full\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = element;

    while (i != 0 && heap->array[(i - 1) / 2].value > heap->array[i].value) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Element extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        Element e = {INT_MAX, -1, -1};
        return e;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    Element root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    MinHeap* minHeap = createMinHeap(numsSize);
    int max = INT_MIN;
    int rangeStart = 0, rangeEnd = INT_MAX;

    // Initialize the heap with the first element from each list
    for (int i = 0; i < numsSize; i++) {
        Element e = {nums[i][0], i, 0};
        insert(minHeap, e);
        if (nums[i][0] > max) max = nums[i][0];
    }

    while (minHeap->size == numsSize) {
        Element curr = extractMin(minHeap);

        if (max - curr.value < rangeEnd - rangeStart) {
            rangeStart = curr.value;
            rangeEnd = max;
        }

        if (curr.index + 1 < numsColSize[curr.list]) {
            int nextValue = nums[curr.list][curr.index + 1];
            Element e = {nextValue, curr.list, curr.index + 1};
            insert(minHeap, e);
            if (nextValue > max) max = nextValue;
        }
    }

    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = rangeStart;
    result[1] = rangeEnd;
    *returnSize = 2;

    // Free allocated memory
    free(minHeap->array);
    free(minHeap);

    return result;
}
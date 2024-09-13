#include <stdlib.h>

// Min-heap structure
typedef struct {
    int* heap;
    int size;
    int capacity;
} MinHeap;

// Function to create a new min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->heap = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with the root at given index
void heapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->heap[left] < minHeap->heap[smallest])
        smallest = left;

    if (right < minHeap->size && minHeap->heap[right] < minHeap->heap[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&minHeap->heap[idx], &minHeap->heap[smallest]);
        heapify(minHeap, smallest);
    }
}

// Function to insert a new element into the min-heap
void insert(MinHeap* minHeap, int key) {
    if (minHeap->size == minHeap->capacity) {
        if (key > minHeap->heap[0]) {
            minHeap->heap[0] = key;
            heapify(minHeap, 0);
        }
    } else {
        minHeap->heap[minHeap->size] = key;
        int i = minHeap->size;
        minHeap->size++;

        while (i != 0 && minHeap->heap[(i - 1) / 2] > minHeap->heap[i]) {
            swap(&minHeap->heap[i], &minHeap->heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    MinHeap* minHeap = createMinHeap(k);

    // Insert first k elements into the min-heap
    for (int i = 0; i < k; i++) {
        insert(minHeap, nums[i]);
    }

    // For remaining elements, if element is larger than root, remove root and insert element
    for (int i = k; i < numsSize; i++) {
        if (nums[i] > minHeap->heap[0]) {
            minHeap->heap[0] = nums[i];
            heapify(minHeap, 0);
        }
    }

    // The root of the min-heap is the kth largest element
    int result = minHeap->heap[0];

    // Free allocated memory
    free(minHeap->heap);
    free(minHeap);

    return result;
}
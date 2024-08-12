#include <stdlib.h>

typedef struct {
    int* heap;
    int size;
    int capacity;
} KthLargest;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(KthLargest* obj, int index) {
    while (index > 0 && obj->heap[(index - 1) / 2] > obj->heap[index]) {
        swap(&obj->heap[(index - 1) / 2], &obj->heap[index]);
        index = (index - 1) / 2;
    }
}

void heapify_down(KthLargest* obj, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < obj->size && obj->heap[left] < obj->heap[smallest])
        smallest = left;

    if (right < obj->size && obj->heap[right] < obj->heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&obj->heap[index], &obj->heap[smallest]);
        heapify_down(obj, smallest);
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;

    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->capacity) {
        obj->heap[obj->size] = val;
        heapify_up(obj, obj->size);
        obj->size++;
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapify_down(obj, 0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/
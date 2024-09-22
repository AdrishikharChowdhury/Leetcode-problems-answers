#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int num1;
    int num2;
} Pair;

int comparePairs(const void* a, const void* b) {
    return ((Pair*)b)->num2 - ((Pair*)a)->num2;
}

void minHeapify(int* heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}

long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    if (nums1Size != nums2Size) return 0;  // Error handling
    int numsSize = nums1Size;

    Pair* pairs = (Pair*)malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        pairs[i].num1 = nums1[i];
        pairs[i].num2 = nums2[i];
    }
    qsort(pairs, numsSize, sizeof(Pair), comparePairs);
    
    int* minHeap = (int*)malloc(k * sizeof(int));
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += pairs[i].num1;
        minHeap[i] = pairs[i].num1;
    }
    for (int i = (k / 2) - 1; i >= 0; i--)
        minHeapify(minHeap, k, i);
    
    long long maxScore = sum * pairs[k-1].num2;
    
    for (int i = k; i < numsSize; i++) {
        if (pairs[i].num1 > minHeap[0]) {
            sum = sum - minHeap[0] + pairs[i].num1;
            minHeap[0] = pairs[i].num1;
            minHeapify(minHeap, k, 0);
            maxScore = MAX(maxScore, sum * pairs[i].num2);
        }
    }
    
    free(pairs);
    free(minHeap);
    return maxScore;
}

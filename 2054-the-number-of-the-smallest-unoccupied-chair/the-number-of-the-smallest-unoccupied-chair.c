#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent arrival events
typedef struct {
    int time;
    int index;
} Arrival;

// Structure to represent occupied chairs
typedef struct {
    int time;
    int chair;
} ChairOccupancy;

// MinHeap structure for available chairs
typedef struct {
    int* chairs;
    int size;
    int capacity;
} MinHeap;

// Function to compare arrivals for qsort
int compareArrivals(const void* a, const void* b) {
    return ((Arrival*)a)->time - ((Arrival*)b)->time;
}

// MinHeap operations
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->chairs[left] < heap->chairs[smallest])
        smallest = left;
    if (right < heap->size && heap->chairs[right] < heap->chairs[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&heap->chairs[idx], &heap->chairs[smallest]);
        heapify(heap, smallest);
    }
}

int extractMin(MinHeap* heap) {
    if (heap->size == 0) return -1;
    
    int root = heap->chairs[0];
    heap->chairs[0] = heap->chairs[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    
    return root;
}

void insertHeap(MinHeap* heap, int chair) {
    if (heap->size == heap->capacity) return;
    
    heap->size++;
    int i = heap->size - 1;
    heap->chairs[i] = chair;
    
    while (i > 0 && heap->chairs[(i - 1) / 2] > heap->chairs[i]) {
        swap(&heap->chairs[i], &heap->chairs[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Main solution function
int smallestChair(int** times, int timesSize, int* timesColSize, int targetFriend) {
    // Create and initialize arrivals array
    Arrival* arrivals = (Arrival*)malloc(timesSize * sizeof(Arrival));
    for (int i = 0; i < timesSize; i++) {
        arrivals[i].time = times[i][0];
        arrivals[i].index = i;
    }
    
    // Sort arrivals by time
    qsort(arrivals, timesSize, sizeof(Arrival), compareArrivals);
    
    // Initialize min heap for available chairs
    MinHeap availableChairs;
    availableChairs.capacity = timesSize;
    availableChairs.size = 0;
    availableChairs.chairs = (int*)malloc(timesSize * sizeof(int));
    
    // Add all chairs to available chairs heap
    for (int i = 0; i < timesSize; i++) {
        insertHeap(&availableChairs, i);
    }
    
    // Array to store leaving times and their chairs
    ChairOccupancy* leavingQueue = (ChairOccupancy*)malloc(timesSize * sizeof(ChairOccupancy));
    int leavingQueueSize = 0;
    
    // Process each arrival
    for (int i = 0; i < timesSize; i++) {
        int currentTime = arrivals[i].time;
        int friendIndex = arrivals[i].index;
        
        // Free up chairs for people who have left
        for (int j = 0; j < leavingQueueSize; j++) {
            if (leavingQueue[j].time <= currentTime) {
                insertHeap(&availableChairs, leavingQueue[j].chair);
                // Remove this entry by shifting the array
                for (int k = j; k < leavingQueueSize - 1; k++) {
                    leavingQueue[k] = leavingQueue[k + 1];
                }
                leavingQueueSize--;
                j--; // Adjust index since we removed an element
            }
        }
        
        // Get the smallest available chair
        int chair = extractMin(&availableChairs);
        
        // If this is our target friend, return their chair
        if (friendIndex == targetFriend) {
            free(arrivals);
            free(availableChairs.chairs);
            free(leavingQueue);
            return chair;
        }
        
        // Add to leaving queue
        leavingQueue[leavingQueueSize].time = times[friendIndex][1];
        leavingQueue[leavingQueueSize].chair = chair;
        leavingQueueSize++;
    }
    
    // Clean up
    free(arrivals);
    free(availableChairs.chairs);
    free(leavingQueue);
    
    return -1; // Should never reach here given constraints
}
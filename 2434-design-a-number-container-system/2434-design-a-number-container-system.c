#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Constants
#define HASH_TABLE_SIZE 131071  // A large prime number for better hash distribution

// Hash map node for index-to-number mapping
typedef struct IndexMapNode {
    int index;
    int number;
    struct IndexMapNode* next;
} IndexMapNode;

// Min-Heap structure for indices
typedef struct MinHeap {
    int* data;
    int size;
    int capacity;
} MinHeap;

// Hash map node for number-to-heap mapping
typedef struct NumberMapNode {
    int number;
    MinHeap* heap;
    struct NumberMapNode* next;
} NumberMapNode;

// Main structure
typedef struct {
    IndexMapNode* indexTable[HASH_TABLE_SIZE];
    NumberMapNode* numberTable[HASH_TABLE_SIZE];
} NumberContainers;

// Hash function
unsigned int hash(int key) {
    return ((unsigned int)key) % HASH_TABLE_SIZE;
}

// Create min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// Swap elements in the heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up to maintain min-heap property
void heapifyUp(MinHeap* heap, int idx) {
    if (idx && heap->data[(idx - 1) / 2] > heap->data[idx]) {
        swap(&heap->data[idx], &heap->data[(idx - 1) / 2]);
        heapifyUp(heap, (idx - 1) / 2);
    }
}

// Insert element into min-heap
void insertMinHeap(MinHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int*)realloc(heap->data, heap->capacity * sizeof(int));
    }
    heap->data[heap->size++] = value;
    heapifyUp(heap, heap->size - 1);
}

// Heapify down to maintain min-heap property
void heapifyDown(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&heap->data[idx], &heap->data[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Extract minimum element from the min-heap
int extractMin(MinHeap* heap) {
    if (heap->size == 0) return -1;
    int min = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapifyDown(heap, 0);
    return min;
}

// Peek the minimum element without extracting
int peekMin(MinHeap* heap) {
    if (heap->size == 0) return -1;
    return heap->data[0];
}

// Create NumberContainers
NumberContainers* numberContainersCreate() {
    NumberContainers* obj = (NumberContainers*)malloc(sizeof(NumberContainers));
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        obj->indexTable[i] = NULL;
        obj->numberTable[i] = NULL;
    }
    return obj;
}

// Insert or update index-to-number mapping
void insertIndexMap(NumberContainers* obj, int index, int number) {
    unsigned int h = hash(index);
    IndexMapNode* node = obj->indexTable[h];
    while (node != NULL) {
        if (node->index == index) {
            node->number = number;
            return;
        }
        node = node->next;
    }
    IndexMapNode* newNode = (IndexMapNode*)malloc(sizeof(IndexMapNode));
    newNode->index = index;
    newNode->number = number;
    newNode->next = obj->indexTable[h];
    obj->indexTable[h] = newNode;
}

// Get number at a specific index
int getNumberAtIndex(NumberContainers* obj, int index) {
    unsigned int h = hash(index);
    IndexMapNode* node = obj->indexTable[h];
    while (node != NULL) {
        if (node->index == index) {
            return node->number;
        }
        node = node->next;
    }
    return -1;
}

// Get or create heap for a number
MinHeap* getOrCreateHeap(NumberContainers* obj, int number) {
    unsigned int h = hash(number);
    NumberMapNode* node = obj->numberTable[h];
    while (node != NULL) {
        if (node->number == number) {
            return node->heap;
        }
        node = node->next;
    }
    NumberMapNode* newNode = (NumberMapNode*)malloc(sizeof(NumberMapNode));
    newNode->number = number;
    newNode->heap = createMinHeap(10);
    newNode->next = obj->numberTable[h];
    obj->numberTable[h] = newNode;
    return newNode->heap;
}

// Change function to insert or replace number at an index
void numberContainersChange(NumberContainers* obj, int index, int number) {
    int oldNumber = getNumberAtIndex(obj, index);
    if (oldNumber != -1 && oldNumber != number) {
        // No explicit removal from heap; lazy removal during find
    }
    insertIndexMap(obj, index, number);
    MinHeap* heap = getOrCreateHeap(obj, number);
    insertMinHeap(heap, index);
}

// Find function to return the smallest valid index for a given number
int numberContainersFind(NumberContainers* obj, int number) {
    unsigned int h = hash(number);
    NumberMapNode* node = obj->numberTable[h];
    while (node != NULL) {
        if (node->number == number) {
            while (node->heap->size > 0) {
                int index = peekMin(node->heap);
                if (getNumberAtIndex(obj, index) == number) {
                    return index;
                } else {
                    extractMin(node->heap);  // Lazy removal of invalid indices
                }
            }
            return -1;
        }
        node = node->next;
    }
    return -1;
}

// Free allocated memory
void numberContainersFree(NumberContainers* obj) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        // Free index table
        IndexMapNode* idxNode = obj->indexTable[i];
        while (idxNode != NULL) {
            IndexMapNode* temp = idxNode;
            idxNode = idxNode->next;
            free(temp);
        }

        // Free number table and heaps
        NumberMapNode* numNode = obj->numberTable[i];
        while (numNode != NULL) {
            free(numNode->heap->data);
            free(numNode->heap);
            NumberMapNode* tempNum = numNode;
            numNode = numNode->next;
            free(tempNum);
        }
    }
    free(obj);
}
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure for MinHeap node
typedef struct {
    int height;
    int row;
    int col;
} HeapNode;

// MinHeap helper functions
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(HeapNode* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent].height > heap[idx].height) {
            swap(&heap[parent], &heap[idx]);
            idx = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(HeapNode* heap, int size, int idx) {
    while (true) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && heap[left].height < heap[smallest].height)
            smallest = left;
        if (right < size && heap[right].height < heap[smallest].height)
            smallest = right;

        if (smallest != idx) {
            swap(&heap[idx], &heap[smallest]);
            idx = smallest;
        } else {
            break;
        }
    }
}

void push(HeapNode* heap, int* size, HeapNode node) {
    heap[*size] = node;
    heapifyUp(heap, *size);
    (*size)++;
}

HeapNode pop(HeapNode* heap, int* size) {
    HeapNode result = heap[0];
    (*size)--;
    heap[0] = heap[*size];
    heapifyDown(heap, *size, 0);
    return result;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize) {
    if (heightMapSize < 3 || heightMapColSize[0] < 3)
        return 0;

    int m = heightMapSize;
    int n = heightMapColSize[0];
    
    // Allocate memory for visited array
    bool** visited = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        visited[i] = (bool*)calloc(n, sizeof(bool));
    }
    
    // Initialize MinHeap
    int maxHeapSize = m * n;
    HeapNode* minHeap = (HeapNode*)malloc(maxHeapSize * sizeof(HeapNode));
    int heapSize = 0;
    
    // Add border cells to heap
    for (int j = 0; j < n; j++) {
        // First row
        push(minHeap, &heapSize, (HeapNode){heightMap[0][j], 0, j});
        visited[0][j] = true;
        // Last row
        push(minHeap, &heapSize, (HeapNode){heightMap[m-1][j], m-1, j});
        visited[m-1][j] = true;
    }
    
    for (int i = 1; i < m-1; i++) {
        // First column
        push(minHeap, &heapSize, (HeapNode){heightMap[i][0], i, 0});
        visited[i][0] = true;
        // Last column
        push(minHeap, &heapSize, (HeapNode){heightMap[i][n-1], i, n-1});
        visited[i][n-1] = true;
    }
    
    // Directions for adjacent cells
    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    int water = 0;
    int maxBoundary = 0;
    
    // Process cells
    while (heapSize > 0) {
        HeapNode curr = pop(minHeap, &heapSize);
        maxBoundary = curr.height > maxBoundary ? curr.height : maxBoundary;
        
        // Check all adjacent cells
        for (int d = 0; d < 4; d++) {
            int newRow = curr.row + dirs[d][0];
            int newCol = curr.col + dirs[d][1];
            
            if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || visited[newRow][newCol])
                continue;
                
            visited[newRow][newCol] = true;
            
            if (heightMap[newRow][newCol] < maxBoundary)
                water += maxBoundary - heightMap[newRow][newCol];
                
            push(minHeap, &heapSize, (HeapNode){heightMap[newRow][newCol], newRow, newCol});
        }
    }
    
    // Free allocated memory
    for (int i = 0; i < m; i++)
        free(visited[i]);
    free(visited);
    free(minHeap);
    
    return water;
}
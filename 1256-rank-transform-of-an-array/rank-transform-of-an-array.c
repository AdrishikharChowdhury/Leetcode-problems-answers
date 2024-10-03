#include <stdlib.h>

// Structure to store number and original index
struct NumIndex {
    int num;
    int index;
};

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return ((struct NumIndex*)a)->num - ((struct NumIndex*)b)->num;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    // Handle empty array
    if (arrSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // Allocate memory for result and NumIndex array
    int* result = (int*)malloc(arrSize * sizeof(int));
    struct NumIndex* numIndices = (struct NumIndex*)malloc(arrSize * sizeof(struct NumIndex));
    *returnSize = arrSize;
    
    // Initialize NumIndex array
    for (int i = 0; i < arrSize; i++) {
        numIndices[i].num = arr[i];
        numIndices[i].index = i;
    }
    
    // Sort based on numbers
    qsort(numIndices, arrSize, sizeof(struct NumIndex), compare);
    
    // Assign ranks
    int rank = 1;
    result[numIndices[0].index] = rank;
    
    for (int i = 1; i < arrSize; i++) {
        if (numIndices[i].num != numIndices[i-1].num) {
            rank++;
        }
        result[numIndices[i].index] = rank;
    }
    
    // Free allocated memory
    free(numIndices);
    
    return result;
}
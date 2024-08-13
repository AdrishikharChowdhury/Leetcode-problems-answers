#include <stdlib.h>
#include <string.h>

void backtrack(int* candidates, int candidatesSize, int target, int start, int* current, int currentSize, int** result, int* resultSize, int** columnSizes) {
    if (target == 0) {
        result[*resultSize] = (int*)malloc(currentSize * sizeof(int));
        memcpy(result[*resultSize], current, currentSize * sizeof(int));
        (*columnSizes)[*resultSize] = currentSize;
        (*resultSize)++;
        return;
    }
    
    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i-1]) continue; // Skip duplicates
        if (candidates[i] > target) break; // Optimization
        
        current[currentSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1, current, currentSize + 1, result, resultSize, columnSizes);
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);
    
    int** result = (int**)malloc(10000 * sizeof(int*)); // Adjust size as needed
    *returnColumnSizes = (int*)malloc(10000 * sizeof(int));
    *returnSize = 0;
    
    int* current = (int*)malloc(candidatesSize * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, current, 0, result, returnSize, returnColumnSizes);
    
    free(current);
    return result;
}
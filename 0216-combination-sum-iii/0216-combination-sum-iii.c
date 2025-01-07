#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int maxCombinations = 100;  // Initial capacity
    int** result = (int**)malloc(maxCombinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCombinations * sizeof(int));
    *returnSize = 0;
    
    // Current combination being built
    int* current = (int*)malloc(k * sizeof(int));
    
    void backtrack(int start, int remainSum, int pos) {
        // Base cases
        if (remainSum < 0 || pos > k) return;
        if (pos == k) {
            if (remainSum == 0) {
                // Valid combination found
                result[*returnSize] = (int*)malloc(k * sizeof(int));
                memcpy(result[*returnSize], current, k * sizeof(int));
                (*returnColumnSizes)[*returnSize] = k;
                (*returnSize)++;
            }
            return;
        }
        
        // Try each possible number
        for (int i = start; i <= 9; i++) {
            current[pos] = i;
            backtrack(i + 1, remainSum - i, pos + 1);
        }
    }
    
    backtrack(1, n, 0);
    
    free(current);
    return result;
}

// Test function
void runTest(int k, int n) {
    int returnSize;
    int* returnColumnSizes;
    int** result = combinationSum3(k, n, &returnSize, &returnColumnSizes);
    
    printf("k = %d, n = %d\n", k, n);
    printf("Output:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(",");
        }
        printf("]\n");
        free(result[i]);
    }
    printf("\n");
    
    free(result);
    free(returnColumnSizes);
}

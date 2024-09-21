#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lexicalOrder(int n, int* returnSize) {
    *returnSize = n;
    int* result = (int*)malloc(n * sizeof(int));
    int current = 1;
    
    for (int i = 0; i < n; i++) {
        result[i] = current;
        if (current * 10 <= n) {
            current *= 10;
        } else {
            if (current >= n)
                current /= 10;
            current++;
            while (current % 10 == 0)
                current /= 10;
        }
    }
    
    return result;
}
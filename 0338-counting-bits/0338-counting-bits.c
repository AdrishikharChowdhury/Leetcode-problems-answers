/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    // Allocate result array of size n+1
    int* result = (int*)malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;
    
    // Base case
    result[0] = 0;
    
    // For each number i
    for (int i = 1; i <= n; i++) {
        // Number of 1's in i = number of 1's in (i >> 1) + last bit
        // i >> 1 is same as i/2
        // i & 1 gives last bit
        result[i] = result[i >> 1] + (i & 1);
    }
    
    return result;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
    // Allocate memory for result array
    int* answer = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Calculate initial XOR of all elements
    int xorSum = 0;
    for (int i = 0; i < numsSize; i++) {
        xorSum ^= nums[i];
    }
    
    // Calculate maximum possible value with maximumBit bits
    int maxValue = (1 << maximumBit) - 1;
    
    // Process each query from last to first
    for (int i = 0; i < numsSize; i++) {
        // Find k that maximizes XOR
        // To maximize XOR with k, we want bits that are opposite of xorSum
        answer[i] = maxValue ^ xorSum;
        
        // Remove last element for next query
        if (i < numsSize - 1) {
            xorSum ^= nums[numsSize - 1 - i];
        }
    }
    
    return answer;
}
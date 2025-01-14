/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    *returnSize = ASize;
    int* C = (int*)malloc(ASize * sizeof(int));
    
    // Create arrays to track seen numbers
    bool* seenA = (bool*)calloc(ASize + 1, sizeof(bool));
    bool* seenB = (bool*)calloc(ASize + 1, sizeof(bool));
    
    int count = 0;
    for (int i = 0; i < ASize; i++) {
        // Mark current numbers as seen
        seenA[A[i]] = true;
        seenB[B[i]] = true;
        
        // If both arrays have seen the current numbers, increment count
        if (seenA[A[i]] && seenB[A[i]]) count++;
        if (A[i] != B[i] && seenA[B[i]] && seenB[B[i]]) count++;
        
        C[i] = count;
    }
    
    // Free allocated memory
    free(seenA);
    free(seenB);
    
    return C;
}
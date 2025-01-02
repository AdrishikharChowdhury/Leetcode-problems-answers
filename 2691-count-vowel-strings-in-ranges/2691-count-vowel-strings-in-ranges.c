bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isVowelString(char* s) {
    int len = strlen(s);
    if (len == 0) return false;
    return isVowel(s[0]) && isVowel(s[len - 1]);
}

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Allocate prefix sum array
    int* prefixSum = (int*)calloc(wordsSize + 1, sizeof(int));
    
    // Build prefix sum array
    for (int i = 0; i < wordsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + (isVowelString(words[i]) ? 1 : 0);
    }
    
    // Process queries
    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        result[i] = prefixSum[right + 1] - prefixSum[left];
    }
    
    // Free memory
    free(prefixSum);
    
    return result;
}
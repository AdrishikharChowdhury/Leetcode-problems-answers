/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void getFrequencyCount(char* word, int* freq) {
    memset(freq, 0, sizeof(int) * 26);
    for (int i = 0; word[i]; i++) {
        freq[word[i] - 'a']++;
    }
}

char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    // Find maximum frequency required for each character from words2
    int maxFreq[26] = {0};
    int tempFreq[26];
    
    for (int i = 0; i < words2Size; i++) {
        getFrequencyCount(words2[i], tempFreq);
        for (int j = 0; j < 26; j++) {
            if (tempFreq[j] > maxFreq[j]) {
                maxFreq[j] = tempFreq[j];
            }
        }
    }
    
    // Allocate space for result
    char** result = (char**)malloc(words1Size * sizeof(char*));
    *returnSize = 0;
    
    // Check each word in words1
    for (int i = 0; i < words1Size; i++) {
        getFrequencyCount(words1[i], tempFreq);
        
        // Check if this word has enough of each required character
        int isValid = 1;
        for (int j = 0; j < 26; j++) {
            if (tempFreq[j] < maxFreq[j]) {
                isValid = 0;
                break;
            }
        }
        
        if (isValid) {
            result[*returnSize] = strdup(words1[i]);
            (*returnSize)++;
        }
    }
    
    // Reallocate to exact size needed
    result = realloc(result, (*returnSize) * sizeof(char*));
    return result;
}
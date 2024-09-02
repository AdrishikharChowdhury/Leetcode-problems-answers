/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize) {
    int minFreq[26] = {0};
    
    // Initialize minFreq with the frequencies of the first word
    for (int i = 0; words[0][i]; i++) {
        minFreq[words[0][i] - 'a']++;
    }
    
    // Update minFreq with the minimum frequencies across all words
    for (int i = 1; i < wordsSize; i++) {
        int freq[26] = {0};
        for (int j = 0; words[i][j]; j++) {
            freq[words[i][j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            minFreq[j] = fmin(minFreq[j], freq[j]);
        }
    }
    
    // Build the result array
    char **result = (char **)malloc(sizeof(char *) * 100);
    *returnSize = 0;
    for (int i = 0; i < 26; i++) {
        while (minFreq[i] > 0) {
            result[(*returnSize)++] = (char *)malloc(sizeof(char) * 2);
            result[*returnSize - 1][0] = 'a' + i;
            result[*returnSize - 1][1] = '\0';
            minFreq[i]--;
        }
    }
    
    return result;
}
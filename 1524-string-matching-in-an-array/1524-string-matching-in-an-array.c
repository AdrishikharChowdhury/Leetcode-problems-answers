/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char** words, int wordsSize, int* returnSize) {
    // Maximum possible substrings would be wordsSize - 1
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    int count = 0;
    bool* found = (bool*)calloc(wordsSize, sizeof(bool)); // Track found words
    
    // Compare each word with every other word
    for (int i = 0; i < wordsSize; i++) {
        if (found[i]) continue; // Skip if already found as substring
        
        for (int j = 0; j < wordsSize; j++) {
            if (i != j) {
                // Check if words[i] is substring of words[j]
                char* pos = strstr(words[j], words[i]);
                if (pos != NULL && strlen(words[i]) < strlen(words[j])) {
                    result[count] = strdup(words[i]); // Copy the string
                    found[i] = true;
                    count++;
                    break; // Found a match, no need to check further
                }
            }
        }
    }
    
    *returnSize = count;
    // Reallocate to exact size needed
    result = realloc(result, count * sizeof(char*));
    free(found);
    return result;
}
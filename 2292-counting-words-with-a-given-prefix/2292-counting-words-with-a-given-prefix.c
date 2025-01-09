

int prefixCount(char** words, int wordsSize, char* pref) {
    int count = 0;
    int prefLen = strlen(pref);
    
    for (int i = 0; i < wordsSize; i++) {
        // Check if current word is at least as long as prefix
        if (strlen(words[i]) < prefLen) {
            continue;
        }
        
        // Check if word starts with prefix
        bool isPrefix = true;
        for (int j = 0; j < prefLen; j++) {
            if (words[i][j] != pref[j]) {
                isPrefix = false;
                break;
            }
        }
        
        if (isPrefix) {
            count++;
        }
    }
    
    return count;
}

// Test function
void runTest(char** words, int wordsSize, char* pref) {
    int result = prefixCount(words, wordsSize, pref);
    printf("Test with prefix \"%s\":\n", pref);
    printf("Words: ");
    for (int i = 0; i < wordsSize; i++) {
        printf("\"%s\" ", words[i]);
    }
    printf("\nResult: %d\n\n", result);
}


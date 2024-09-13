#include <stdbool.h>
#include <string.h>

int countConsistentStrings(char* allowed, char** words, int wordsSize) {
    // Create an array to mark allowed characters
    bool isAllowed[128] = {false};  // Assuming ASCII characters
    
    // Mark allowed characters
    for (int i = 0; allowed[i] != '\0'; i++) {
        isAllowed[(unsigned char)allowed[i]] = true;
    }
    
    int count = 0;
    
    // Check each word
    for (int i = 0; i < wordsSize; i++) {
        bool isConsistent = true;
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (!isAllowed[(unsigned char)words[i][j]]) {
                isConsistent = false;
                break;
            }
        }
        if (isConsistent) {
            count++;
        }
    }
    
    return count;
}
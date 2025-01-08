#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPrefixAndSuffix(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // If str1 is longer than str2, it can't be both prefix and suffix
    if (len1 > len2) {
        return false;
    }
    
    // Check prefix
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    
    // Check suffix
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[len2 - len1 + i]) {
            return false;
        }
    }
    
    return true;
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    int count = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (isPrefixAndSuffix(words[i], words[j])) {
                count++;
            }
        }
    }
    
    return count;
}

// Test function
void runTest(char** words, int size, int expected) {
    int result = countPrefixSuffixPairs(words, size);
    printf("Test case result: %d (Expected: %d)\n", result, expected);
}

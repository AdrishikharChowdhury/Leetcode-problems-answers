#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper function to split sentence into words
char** splitSentence(char* sentence, int* wordCount) {
    *wordCount = 1;
    for (int i = 0; sentence[i]; i++) {
        if (sentence[i] == ' ') (*wordCount)++;
    }
    
    char** words = (char**)malloc(*wordCount * sizeof(char*));
    char* token = strtok(sentence, " ");
    int index = 0;
    
    while (token != NULL) {
        words[index] = strdup(token);
        token = strtok(NULL, " ");
        index++;
    }
    
    return words;
}

bool areSentencesSimilar(char* sentence1, char* sentence2) {
    // Create copies of sentences as strtok modifies the original string
    char* s1_copy = strdup(sentence1);
    char* s2_copy = strdup(sentence2);
    
    int count1, count2;
    char** words1 = splitSentence(s1_copy, &count1);
    char** words2 = splitSentence(s2_copy, &count2);
    
    // Ensure sentence1 is the shorter one
    if (count1 > count2) {
        char** tempWords = words1;
        words1 = words2;
        words2 = tempWords;
        int tempCount = count1;
        count1 = count2;
        count2 = tempCount;
    }
    
    int left = 0;
    // Match words from left
    while (left < count1 && strcmp(words1[left], words2[left]) == 0) {
        left++;
    }
    
    int right = 0;
    // Match words from right
    while (right < count1 - left && 
           strcmp(words1[count1 - 1 - right], 
                 words2[count2 - 1 - right]) == 0) {
        right++;
    }
    
    // Free allocated memory
    for (int i = 0; i < count1; i++) free(words1[i]);
    for (int i = 0; i < count2; i++) free(words2[i]);
    free(words1);
    free(words2);
    free(s1_copy);
    free(s2_copy);
    
    return (left + right) >= count1;
}


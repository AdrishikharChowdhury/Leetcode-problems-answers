#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 200
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    WordCount wordCounts[MAX_WORDS] = {0};
    int wordCountSize = 0;

    // Helper function to count words
    void countWords(char* s) {
        char* token = strtok(s, " ");
        while (token != NULL) {
            int found = 0;
            for (int i = 0; i < wordCountSize; i++) {
                if (strcmp(wordCounts[i].word, token) == 0) {
                    wordCounts[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(wordCounts[wordCountSize].word, token);
                wordCounts[wordCountSize].count = 1;
                wordCountSize++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Count words in both sentences
    char* s1_copy = strdup(s1);
    char* s2_copy = strdup(s2);
    countWords(s1_copy);
    countWords(s2_copy);
    free(s1_copy);
    free(s2_copy);

    // Find uncommon words
    char** result = malloc(MAX_WORDS * sizeof(char*));
    *returnSize = 0;
    for (int i = 0; i < wordCountSize; i++) {
        if (wordCounts[i].count == 1) {
            result[*returnSize] = strdup(wordCounts[i].word);
            (*returnSize)++;
        }
    }

    return result;
}
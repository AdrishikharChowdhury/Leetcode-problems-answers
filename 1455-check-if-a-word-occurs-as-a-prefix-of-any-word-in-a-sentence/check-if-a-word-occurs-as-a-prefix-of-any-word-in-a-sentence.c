#include <string.h>
#include <stdio.h>

int isPrefixOfWord(char* sentence, char* searchWord) {
    // Tokenize the sentence into words
    char *word = strtok(sentence, " ");
    int index = 1;

    // Iterate over each word in the sentence
    while (word != NULL) {
        // Check if searchWord is a prefix of the current word
        if (strncmp(word, searchWord, strlen(searchWord)) == 0) {
            return index;  // Return the 1-indexed position
        }
        word = strtok(NULL, " ");
        index++;
    }

    return -1;  // If no match, return -1
}
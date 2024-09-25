#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie node structure
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int count;
} TrieNode;

// Function to create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node) {
        node->count = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

// Function to insert a word into the Trie
void insertWord(TrieNode* root, const char* word) {
    TrieNode* node = root;
    while (*word) {
        int index = *word - 'a';
        if (!node->children[index]) {
            node->children[index] = createNode();
        }
        node = node->children[index];
        node->count++;
        word++;
    }
}

// Function to calculate the score for a word
int calculateScore(TrieNode* root, const char* word) {
    TrieNode* node = root;
    int score = 0;
    while (*word) {
        int index = *word - 'a';
        if (!node->children[index]) {
            break;
        }
        node = node->children[index];
        score += node->count;
        word++;
    }
    return score;
}

// Function to free the Trie
void freeTrie(TrieNode* node) {
    if (node) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i]) {
                freeTrie(node->children[i]);
            }
        }
        free(node);
    }
}

// Main function to solve the problem
int* sumPrefixScores(char** words, int wordsSize, int* returnSize) {
    TrieNode* root = createNode();
    
    // Build the Trie
    for (int i = 0; i < wordsSize; i++) {
        insertWord(root, words[i]);
    }
    
    // Calculate scores
    int* answer = (int*)malloc(wordsSize * sizeof(int));
    *returnSize = wordsSize;
    
    for (int i = 0; i < wordsSize; i++) {
        answer[i] = calculateScore(root, words[i]);
    }
    
    // Free the Trie
    freeTrie(root);
    
    return answer;
}


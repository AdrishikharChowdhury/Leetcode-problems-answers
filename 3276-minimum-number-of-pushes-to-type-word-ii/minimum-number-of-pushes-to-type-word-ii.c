#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b, void* arg) {
    int* freq = (int*)arg;
    return freq[*(int*)b] - freq[*(int*)a];
}

int minimumPushes(char* word) {
    int freq[26] = {0};
    int len = strlen(word);
    
    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        freq[word[i] - 'a']++;
    }
    
    // Create array of indices
    int indices[26];
    for (int i = 0; i < 26; i++) {
        indices[i] = i;
    }
    
    // Sort indices based on frequency
    qsort_r(indices, 26, sizeof(int), compare, freq);
    
    int pushes = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[indices[i]] == 0) break;
        pushes += freq[indices[i]] * (1 + i / 8);
    }
    
    return pushes;
}
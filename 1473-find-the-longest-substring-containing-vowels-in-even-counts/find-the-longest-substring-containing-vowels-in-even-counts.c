#include <string.h>

int findTheLongestSubstring(char * s) {
    const char* vowels = "aeiou";
    int state = 0;
    int first_occurrence[32];
    int max_length = 0;
    int len = strlen(s);
    
    // Initialize all states to -1
    for (int i = 0; i < 32; i++) {
        first_occurrence[i] = -1;
    }
    first_occurrence[0] = 0;  // Initialize the first occurrence of state 0 to 0 (before the string starts)
    
    for (int i = 0; i < len; i++) {
        char* p = strchr(vowels, s[i]);
        if (p != NULL) {
            int index = p - vowels;
            state ^= (1 << index);  // Flip the corresponding bit in the state
        }
        
        if (first_occurrence[state] != -1) {
            int length = i + 1 - first_occurrence[state];
            if (length > max_length) {
                max_length = length;
            }
        } else {
            first_occurrence[state] = i + 1;  // Store the first occurrence as i + 1
        }
    }
    
    return max_length;
}

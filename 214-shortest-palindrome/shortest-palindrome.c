#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the KMP failure function
void computeLPS(char* pattern, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

char* shortestPalindrome(char* s) {
    int len = strlen(s);
    if (len <= 1) return s;

    // Create a new string in the format s#reverse(s)
    char* new_s = (char*)malloc(sizeof(char) * (2 * len + 2));
    strcpy(new_s, s);
    new_s[len] = '#';
    for (int i = 0; i < len; i++) {
        new_s[len + 1 + i] = s[len - 1 - i];
    }
    new_s[2 * len + 1] = '\0';

    // Compute KMP failure function
    int* lps = (int*)malloc(sizeof(int) * (2 * len + 1));
    computeLPS(new_s, 2 * len + 1, lps);

    // The last entry of lps array gives us the length of the longest palindrome prefix
    int palindrome_len = lps[2 * len];

    // Construct the result
    char* result = (char*)malloc(sizeof(char) * (2 * len - palindrome_len + 1));
    for (int i = len - 1; i >= palindrome_len; i--) {
        result[len - 1 - i] = s[i];
    }
    strcpy(result + (len - palindrome_len), s);

    free(new_s);
    free(lps);

    return result;
}
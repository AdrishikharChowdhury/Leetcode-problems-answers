#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 > len2) return false;

    int freq_s1[26] = {0}, freq_window[26] = {0};

    // Initialize frequency arrays for s1 and the first window in s2
    for (int i = 0; i < len1; i++) {
        freq_s1[s1[i] - 'a']++;
        freq_window[s2[i] - 'a']++;
    }

    // Compare the initial window
    if (memcmp(freq_s1, freq_window, sizeof(freq_s1)) == 0) return true;

    // Sliding window technique
    for (int i = len1; i < len2; i++) {
        freq_window[s2[i] - 'a']++;        // Add new character to window
        freq_window[s2[i - len1] - 'a']--; // Remove old character from window

        if (memcmp(freq_s1, freq_window, sizeof(freq_s1)) == 0) return true;
    }

    return false;
}
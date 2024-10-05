#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // If s1 is longer than s2, return false
    if (len1 > len2) return false;
    
    // Create frequency arrays
    int s1_count[26] = {0};
    int window_count[26] = {0};
    
    // Count frequencies for s1
    for (int i = 0; i < len1; i++) {
        s1_count[s1[i] - 'a']++;
    }
    
    // Initialize first window
    for (int i = 0; i < len1; i++) {
        window_count[s2[i] - 'a']++;
    }
    
    // Check first window
    bool match = true;
    for (int i = 0; i < 26; i++) {
        if (s1_count[i] != window_count[i]) {
            match = false;
            break;
        }
    }
    if (match) return true;
    
    // Slide window and check remaining
    for (int i = len1; i < len2; i++) {
        // Remove leftmost character
        window_count[s2[i - len1] - 'a']--;
        // Add rightmost character
        window_count[s2[i] - 'a']++;
        
        // Check current window
        match = true;
        for (int j = 0; j < 26; j++) {
            if (s1_count[j] != window_count[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    
    return false;
}
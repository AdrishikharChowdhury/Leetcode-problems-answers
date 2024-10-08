#include <stdio.h>
#include <string.h>

int minSwaps(char* s) {
    // Keep track of unmatched closing brackets
    int unmatched = 0;
    // Keep track of maximum number of unmatched closing brackets
    int maxUnmatched = 0;
    
    // Iterate through the string
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '[') {
            // Opening bracket reduces unmatched count
            unmatched--;
        } else {
            // Closing bracket increases unmatched count
            unmatched++;
        }
        // Update maximum unmatched count
        maxUnmatched = unmatched > maxUnmatched ? unmatched : maxUnmatched;
    }
    
    // The minimum number of swaps needed is (maxUnmatched + 1) / 2
    return (maxUnmatched + 1) / 2;
}

// Function to test the implementation
void runTest(char* s, int expected) {
    int result = minSwaps(s);
    printf("Input: %s\n", s);
    printf("Output: %d\n", result);
    printf("Expected: %d\n", expected);
    printf("Test %s\n\n", result == expected ? "PASSED" : "FAILED");
}


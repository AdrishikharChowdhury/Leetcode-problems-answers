#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minLength(char* s) {
    // Create a stack to store characters
    char* stack = (char*)malloc(strlen(s) + 1);
    int top = 0;
    
    // Process each character in the string
    for (int i = 0; s[i] != '\0'; i++) {
        if (top > 0) {  // If stack has at least one character
            if ((s[i] == 'B' && stack[top-1] == 'A') || 
                (s[i] == 'D' && stack[top-1] == 'C')) {
                // Pop the previous character if it forms "AB" or "CD"
                top--;
                continue;
            }
        }
        // Push current character to stack
        stack[top++] = s[i];
    }
    
    // Clean up
    free(stack);
    
    return top;
}

// Function to test the implementation
void runTest(char* s, int expected) {
    int result = minLength(s);
    printf("Input: %s\n", s);
    printf("Output: %d\n", result);
    printf("Expected: %d\n", expected);
    printf("Test %s\n\n", result == expected ? "PASSED" : "FAILED");
}


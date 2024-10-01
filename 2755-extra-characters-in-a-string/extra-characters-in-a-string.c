#include <string.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minExtraChar(char* s, char** dictionary, int dictionarySize) {
    int n = strlen(s);
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    
    // Base case
    dp[0] = 0;
    
    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        // Initially assume the current character is extra
        dp[i] = dp[i - 1] + 1;
        
        // Check all possible word endings at index i
        for (int j = 0; j < dictionarySize; j++) {
            int len = strlen(dictionary[j]);
            if (i >= len && strncmp(s + i - len, dictionary[j], len) == 0) {
                dp[i] = MIN(dp[i], dp[i - len]);
            }
        }
    }
    
    // The answer is in dp[n]
    int result = dp[n];
    
    // Free the allocated memory
    free(dp);
    
    return result;
}
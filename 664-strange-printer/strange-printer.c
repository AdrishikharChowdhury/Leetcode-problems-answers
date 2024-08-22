#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int strangePrinter(char* s) {
    int n = strlen(s);
    int dp[n][n];
    
    // Initialize the dp array with the worst case
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = n;  // Set to maximum possible value initially
        }
        dp[i][i] = 1;  // Single character takes 1 turn
    }
    
    // Fill the dp array for substrings of length greater than 1
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i][j - 1];  // If ends match, it may need fewer turns
            } else {
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }
    
    return dp[0][n - 1];
}

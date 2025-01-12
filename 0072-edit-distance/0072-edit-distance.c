int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    
    // Create DP table with size (m+1) x (n+1)
    int dp[501][501];
    
    // Initialize first row and column
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;  // Cost of deleting all characters
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;  // Cost of inserting all characters
    }
    
    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];  // No operation needed
            } else {
                // Take minimum of insert, delete, or replace
                int insert = dp[i][j-1] + 1;
                int delete = dp[i-1][j] + 1;
                int replace = dp[i-1][j-1] + 1;
                
                dp[i][j] = insert;
                if (delete < dp[i][j]) dp[i][j] = delete;
                if (replace < dp[i][j]) dp[i][j] = replace;
            }
        }
    }
    
    return dp[m][n];
}
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        
        // Create DP table with size (m+1) x (n+1)
        int[][] dp = new int[m + 1][n + 1];
        
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
                if (word1.charAt(i-1) == word2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1];  // No operation needed
                } else {
                    // Take minimum of insert, delete, or replace
                    dp[i][j] = Math.min(
                        dp[i][j-1] + 1,    // Insert
                        Math.min(
                            dp[i-1][j] + 1,    // Delete
                            dp[i-1][j-1] + 1   // Replace
                        )
                    );
                }
            }
        }
        
        return dp[m][n];
    }
}
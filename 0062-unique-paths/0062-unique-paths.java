class Solution {
    public int uniquePaths(int m, int n) {
        // Create a 2D DP array
        long[][] dp = new long[m][n];
        
        // Initialize first row
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        
        // Initialize first column
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        
        // Fill the dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return (int)dp[m-1][n-1];
    }
}
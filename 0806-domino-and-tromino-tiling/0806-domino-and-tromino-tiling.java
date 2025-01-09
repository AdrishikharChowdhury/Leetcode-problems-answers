class Solution {
    public int numTilings(int n) {
        final int MOD = 1000000007;
        if (n <= 2) return n;
        if (n == 3) return 5;
        
        // Use long to prevent overflow during calculations
        long[] dp = new long[n + 1];
        dp[1] = 1;  // One way to tile 2x1 board
        dp[2] = 2;  // Two ways to tile 2x2 board
        dp[3] = 5;  // Five ways to tile 2x3 board
        
        // For n > 3, we use the recurrence relation:
        // dp[n] = 2 * dp[n-1] + dp[n-3]
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i-1] % MOD + dp[i-3] % MOD) % MOD;
        }
        
        return (int)dp[n];
    }
}
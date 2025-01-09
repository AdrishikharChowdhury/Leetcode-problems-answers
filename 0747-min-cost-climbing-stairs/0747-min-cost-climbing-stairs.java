class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        
        // Base cases
        if (n <= 1) return 0;
        
        // Create dp array
        int[] dp = new int[n + 1];
        
        // Base cases for dp
        dp[0] = 0;  // Cost to reach before first step
        dp[1] = 0;  // Cost to reach before second step
        
        // Fill dp array
        for (int i = 2; i <= n; i++) {
            dp[i] = Math.min(dp[i-1] + cost[i-1],     // Cost if coming from previous step
                            dp[i-2] + cost[i-2]);      // Cost if coming from two steps before
        }
        
        return dp[n];
    }

}
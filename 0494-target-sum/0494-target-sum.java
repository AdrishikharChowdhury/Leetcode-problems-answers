class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        // If target is out of possible range
        if (Math.abs(target) > sum) return 0;
        
        // dp[i][j] represents number of ways to achieve sum j using first i numbers
        int[][] dp = new int[nums.length + 1][2 * sum + 1];
        dp[0][sum] = 1;  // Base case: empty subset gives sum 0
        
        // Fill dp table
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < 2 * sum + 1; j++) {
                if (dp[i][j] != 0) {
                    dp[i + 1][j + nums[i]] += dp[i][j];
                    dp[i + 1][j - nums[i]] += dp[i][j];
                }
            }
        }
        
        return dp[nums.length][sum + target];
    }
}
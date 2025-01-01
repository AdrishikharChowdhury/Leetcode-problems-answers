int findTargetSumWays(int* nums, int numsSize, int target) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    
    // If target is out of possible range
    if (abs(target) > sum) return 0;
    
    // dp[i][j] represents number of ways to achieve sum j using first i numbers
    int width = 2 * sum + 1;
    int** dp = (int**)malloc((numsSize + 1) * sizeof(int*));
    for (int i = 0; i <= numsSize; i++) {
        dp[i] = (int*)calloc(width, sizeof(int));
    }
    
    // Base case: empty subset gives sum 0
    dp[0][sum] = 1;
    
    // Fill dp table
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < width; j++) {
            if (dp[i][j] != 0) {
                // Add current number
                if (j + nums[i] < width) {
                    dp[i + 1][j + nums[i]] += dp[i][j];
                }
                // Subtract current number
                if (j - nums[i] >= 0) {
                    dp[i + 1][j - nums[i]] += dp[i][j];
                }
            }
        }
    }
    
    int result = dp[numsSize][sum + target];
    
    // Free memory
    for (int i = 0; i <= numsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}
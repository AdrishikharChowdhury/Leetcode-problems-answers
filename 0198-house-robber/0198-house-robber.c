#include <stdio.h>

int rob(int* nums, int numsSize) {
    // Handle base cases
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
    
    // Initialize dp array with first two decisions
    int dp[100];  // Based on constraints: 1 <= numsSize <= 100
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    
    // Fill dp array
    for (int i = 2; i < numsSize; i++) {
        dp[i] = dp[i-1] > (dp[i-2] + nums[i]) ? dp[i-1] : (dp[i-2] + nums[i]);
    }
    
    return dp[numsSize-1];
}
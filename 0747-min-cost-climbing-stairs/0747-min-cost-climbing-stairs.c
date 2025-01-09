#include <stdio.h>
#include <stdlib.h>

int minCostClimbingStairs(int* cost, int costSize) {
    // Base cases
    if (costSize <= 1) return 0;
    
    // Create dp array
    int* dp = (int*)malloc((costSize + 1) * sizeof(int));
    
    // Base cases for dp
    dp[0] = 0;  // Cost to reach before first step
    dp[1] = 0;  // Cost to reach before second step
    
    // Fill dp array
    for (int i = 2; i <= costSize; i++) {
        dp[i] = fmin(dp[i-1] + cost[i-1],    // Cost if coming from previous step
                     dp[i-2] + cost[i-2]);    // Cost if coming from two steps before
    }
    
    int result = dp[costSize];
    free(dp);
    return result;
}

// Test function
void runTest(int* cost, int size) {
    int result = minCostClimbingStairs(cost, size);
    printf("Input: [");
    for (int i = 0; i < size; i++) {
        printf("%d", cost[i]);
        if (i < size - 1) printf(",");
    }
    printf("]\nMinimum cost: %d\n\n", result);
}


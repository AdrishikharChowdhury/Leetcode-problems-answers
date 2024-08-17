#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long maxPoints(int** points, int pointsSize, int* pointsColSize) {
    int m = pointsSize;
    int n = pointsColSize[0];
    long long* dp = (long long*)malloc(n * sizeof(long long));
    
    // Initialize first row
    for (int j = 0; j < n; j++) {
        dp[j] = points[0][j];
    }
    
    for (int i = 1; i < m; i++) {
        long long* newDp = (long long*)malloc(n * sizeof(long long));
        long long leftMax = 0;
        
        // Left to right
        for (int j = 0; j < n; j++) {
            leftMax = MAX(leftMax - 1, dp[j]);
            newDp[j] = leftMax;
        }
        
        long long rightMax = 0;
        // Right to left
        for (int j = n - 1; j >= 0; j--) {
            rightMax = MAX(rightMax - 1, dp[j]);
            newDp[j] = MAX(newDp[j], rightMax) + points[i][j];
        }
        
        free(dp);
        dp = newDp;
    }
    
    long long maxPoints = 0;
    for (int j = 0; j < n; j++) {
        maxPoints = MAX(maxPoints, dp[j]);
    }
    
    free(dp);
    return maxPoints;
}
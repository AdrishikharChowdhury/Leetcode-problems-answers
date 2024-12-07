#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Function to get maximum number of balls
int getMaxBalls(int* nums, int numsSize) {
    int max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

// Check if a given penalty is achievable within max operations
bool canAchievePenalty(int* nums, int numsSize, int penalty, int maxOperations) {
    int operationsNeeded = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // Calculate operations needed to divide this bag
        operationsNeeded += (nums[i] - 1) / penalty;
    }
    
    return operationsNeeded <= maxOperations;
}

// Main solution function
int minimumSize(int* nums, int numsSize, int maxOperations) {
    // Input validation
    if (nums == NULL || numsSize == 0 || maxOperations < 0) {
        return -1;  // Invalid input
    }
    
    // Special case: if no operations allowed
    if (maxOperations == 0) {
        return getMaxBalls(nums, numsSize);
    }
    
    // Set the search range
    int left = 1;
    int right = getMaxBalls(nums, numsSize);
    
    // Binary search for minimum penalty
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // Check if mid is a valid penalty
        if (canAchievePenalty(nums, numsSize, mid, maxOperations)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}
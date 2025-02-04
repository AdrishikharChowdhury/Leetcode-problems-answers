int maxAscendingSum(int* nums, int numsSize) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        // If current number is greater than previous, add to current sum
        if (nums[i] > nums[i - 1]) {
            currentSum += nums[i];
        } else {
            // Start new sequence
            currentSum = nums[i];
        }
        // Update maximum sum if current sum is larger
        maxSum = currentSum > maxSum ? currentSum : maxSum;
    }
    
    return maxSum;
}
// C Solution
int waysToSplitArray(int* nums, int numsSize) {
    long long totalSum = 0;  // Using long long to handle potential overflow
    long long leftSum = 0;
    int validSplits = 0;
    
    // Calculate total sum
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }
    
    // Check each possible split point
    for (int i = 0; i < numsSize - 1; i++) {  // numsSize-1 because we need at least one element on right
        leftSum += nums[i];
        long long rightSum = totalSum - leftSum;
        
        if (leftSum >= rightSum) {
            validSplits++;
        }
    }
    
    return validSplits;
}
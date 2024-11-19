#define MAX_NUM 100001

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    long long maxSum = 0;
    long long currSum = 0;
    int freq[MAX_NUM] = {0};
    int distinctCount = 0;
    
    // First window
    for (int i = 0; i < k; i++) {
        currSum += nums[i];
        if (freq[nums[i]] == 0) distinctCount++;
        freq[nums[i]]++;
    }
    
    // Check first window
    if (distinctCount == k) maxSum = currSum;
    
    // Slide window
    for (int i = k; i < numsSize; i++) {
        // Remove previous window's leftmost element
        freq[nums[i-k]]--;
        if (freq[nums[i-k]] == 0) distinctCount--;
        currSum -= nums[i-k];
        
        // Add new element
        currSum += nums[i];
        if (freq[nums[i]] == 0) distinctCount++;
        freq[nums[i]]++;
        
        // Update max sum
        if (distinctCount == k) {
            maxSum = (maxSum > currSum) ? maxSum : currSum;
        }
    }
    
    return maxSum;
}
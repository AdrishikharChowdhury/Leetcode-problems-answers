int longestMonotonicSubarray(int* nums, int numsSize) {
    int maxLen = 1;
    int currIncLen = 1;  // Current increasing sequence length
    int currDecLen = 1;  // Current decreasing sequence length
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            // Continue increasing sequence
            currIncLen++;
            // Reset decreasing sequence
            currDecLen = 1;
        } else if (nums[i] < nums[i - 1]) {
            // Continue decreasing sequence
            currDecLen++;
            // Reset increasing sequence
            currIncLen = 1;
        } else {
            // Equal elements reset both sequences
            currIncLen = 1;
            currDecLen = 1;
        }
        
        // Update maximum length
        int currMax = currIncLen > currDecLen ? currIncLen : currDecLen;
        maxLen = maxLen > currMax ? maxLen : currMax;
    }
    
    return maxLen;
}

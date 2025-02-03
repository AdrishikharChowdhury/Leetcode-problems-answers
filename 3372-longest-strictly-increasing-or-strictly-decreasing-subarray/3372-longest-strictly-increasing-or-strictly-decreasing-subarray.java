class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        int maxLen = 1;
        int currIncLen = 1;  // Current increasing sequence length
        int currDecLen = 1;  // Current decreasing sequence length
        
        for (int i = 1; i < n; i++) {
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
            
            maxLen = Math.max(maxLen, Math.max(currIncLen, currDecLen));
        }
        
        return maxLen;
    }
}
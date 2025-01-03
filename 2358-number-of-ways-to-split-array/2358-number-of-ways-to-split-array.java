// Java Solution
class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length;
        long totalSum = 0;  // Using long to handle potential overflow
        long leftSum = 0;
        int validSplits = 0;
        
        // Calculate total sum
        for (int num : nums) {
            totalSum += num;
        }
        
        // Check each possible split point
        for (int i = 0; i < n - 1; i++) {  // n-1 because we need at least one element on right
            leftSum += nums[i];
            long rightSum = totalSum - leftSum;
            
            if (leftSum >= rightSum) {
                validSplits++;
            }
        }
        
        return validSplits;
    }
}
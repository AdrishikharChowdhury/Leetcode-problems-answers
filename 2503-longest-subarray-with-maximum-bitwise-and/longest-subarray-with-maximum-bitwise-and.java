class Solution {
    public int longestSubarray(int[] nums) {
        int maxNum = 0;
        
        // Find the maximum number in the array
        for (int num : nums) {
            maxNum = Math.max(maxNum, num);
        }
        
        int currentLength = 0;
        int maxLength = 0;
        
        // Find the longest consecutive sequence of maxNum
        for (int num : nums) {
            if (num == maxNum) {
                currentLength++;
                maxLength = Math.max(maxLength, currentLength);
            } else {
                currentLength = 0;
            }
        }
        
        return maxLength;
    }
}
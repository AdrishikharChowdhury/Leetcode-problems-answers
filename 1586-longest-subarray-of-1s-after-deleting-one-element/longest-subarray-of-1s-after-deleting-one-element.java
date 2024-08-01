class Solution {
    public int longestSubarray(int[] nums) {
        int left = 0, right;
        int zeroCount = 0;
        int maxLength = 0;
        
        for (right = 0; right < nums.length; right++) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            maxLength = Math.max(maxLength, right - left);
        }
        
        return maxLength;
    }
}
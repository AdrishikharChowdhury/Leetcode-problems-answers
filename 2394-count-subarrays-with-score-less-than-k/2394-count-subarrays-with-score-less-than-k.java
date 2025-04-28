class Solution {
    public long countSubarrays(int[] nums, long k) {
        long count = 0;
        long sum = 0;
        int left = 0;
        
        for (int right = 0; right < nums.length; right++) {
            // Add current element to sum
            sum += nums[right];
            
            // Shrink window from left while score is too large
            while (left <= right && sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }
            
            // Add count of all valid subarrays ending at right
            count += (right - left + 1);
        }
        
        return count;
    }
}
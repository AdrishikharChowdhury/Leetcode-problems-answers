class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long maxSum = 0;
        long currSum = 0;
        Map<Integer, Integer> window = new HashMap<>();
        
        // First window
        for (int i = 0; i < k; i++) {
            currSum += nums[i];
            window.put(nums[i], window.getOrDefault(nums[i], 0) + 1);
        }
        
        // Check first window
        if (window.size() == k) maxSum = currSum;
        
        // Slide window
        for (int i = k; i < nums.length; i++) {
            // Remove leftmost element
            window.put(nums[i-k], window.get(nums[i-k]) - 1);
            if (window.get(nums[i-k]) == 0) {
                window.remove(nums[i-k]);
            }
            currSum -= nums[i-k];
            
            // Add new element
            currSum += nums[i];
            window.put(nums[i], window.getOrDefault(nums[i], 0) + 1);
            
            // Update max sum
            if (window.size() == k) {
                maxSum = Math.max(maxSum, currSum);
            }
        }
        
        return maxSum;
    }
}
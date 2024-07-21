class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;
        
        // Calculate the sum of the first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        int maxSum = sum;
        
        // Slide the window and update the sum
        for (int i = k; i < nums.length; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = Math.max(maxSum, sum);
        }
        
        // Return the maximum average
        return (double) maxSum / k;
    }
}
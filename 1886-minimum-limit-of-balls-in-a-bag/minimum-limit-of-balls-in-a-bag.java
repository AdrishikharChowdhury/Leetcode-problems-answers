class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        // Set the search range
        int left = 1;
        int right = getMaxBalls(nums);
        
        // Binary search for minimum penalty
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid is a valid penalty
            if (canAchievePenalty(nums, mid, maxOperations)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    // Check if given penalty is achievable within maxOperations
    private boolean canAchievePenalty(int[] nums, int penalty, int maxOperations) {
        int operationsNeeded = 0;
        
        for (int balls : nums) {
            // Calculate operations needed to divide this bag
            operationsNeeded += (balls - 1) / penalty;
        }
        
        return operationsNeeded <= maxOperations;
    }
    
    // Find the maximum number of balls in any bag
    private int getMaxBalls(int[] nums) {
        int max = nums[0];
        for (int balls : nums) {
            max = Math.max(max, balls);
        }
        return max;
    }
}
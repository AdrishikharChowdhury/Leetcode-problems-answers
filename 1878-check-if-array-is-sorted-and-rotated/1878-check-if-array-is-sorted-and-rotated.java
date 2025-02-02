class Solution {
    public boolean check(int[] nums) {
        // Count the number of times adjacent elements decrease
        int count = 0;
        int n = nums.length;
        
        for (int i = 0; i < n; i++) {
            // Compare current element with next element
            // For last element, compare with first element using modulo
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            
            // If we find more than one decrease, it's impossible
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
}
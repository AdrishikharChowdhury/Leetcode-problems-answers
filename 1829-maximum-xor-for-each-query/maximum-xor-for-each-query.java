class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int n = nums.length;
        int[] answer = new int[n];
        
        // Calculate initial XOR of all elements
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        // Calculate maximum possible value with maximumBit bits
        int maxValue = (1 << maximumBit) - 1;
        
        // Process each query from last to first
        for (int i = 0; i < n; i++) {
            // Find k that maximizes XOR
            // To maximize XOR with k, we want bits that are opposite of xorSum
            answer[i] = maxValue ^ xorSum;
            
            // Remove last element for next query
            if (i < n - 1) {
                xorSum ^= nums[n - 1 - i];
            }
        }
        
        return answer;
    }
}
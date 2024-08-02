class Solution {
    public int minSwaps(int[] nums) {
        int totalOnes = 0;
        for (int num : nums) {
            totalOnes += num;
        }
        
        if (totalOnes == 0) return 0;
        
        int n = nums.length;
        int[] extendedNums = new int[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            extendedNums[i] = nums[i % n];
        }
        
        int currentOnes = 0;
        int maxOnes = 0;
        
        // Initialize the first window
        for (int i = 0; i < totalOnes; i++) {
            currentOnes += extendedNums[i];
        }
        maxOnes = currentOnes;
        
        // Slide the window
        for (int i = totalOnes; i < 2 * n; i++) {
            currentOnes += extendedNums[i] - extendedNums[i - totalOnes];
            maxOnes = Math.max(maxOnes, currentOnes);
        }
        
        return totalOnes - maxOnes;
    }
}
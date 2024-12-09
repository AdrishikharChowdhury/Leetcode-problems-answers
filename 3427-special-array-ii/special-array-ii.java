class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        
        // Precompute problematic indices
        boolean[] isProblem = new boolean[n - 1];
        for (int i = 0; i < n - 1; i++) {
            isProblem[i] = (nums[i] % 2 == nums[i + 1] % 2);
        }
        
        // Precompute prefix sum of problems
        int[] prefixSum = new int[n];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + (isProblem[i - 1] ? 1 : 0);
        }
        
        // Process queries
        boolean[] result = new boolean[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int from = queries[i][0];
            int to = queries[i][1];
            
            // Check if any problem in the range
            result[i] = (prefixSum[to] - prefixSum[from]) == 0;
        }
        
        return result;
    }
}
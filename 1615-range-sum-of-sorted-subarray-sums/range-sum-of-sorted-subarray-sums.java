class Solution {
    private static final int MOD = 1000000007;
    
    public int rangeSum(int[] nums, int n, int left, int right) {
        int[] sums = new int[n * (n + 1) / 2];
        int index = 0;
        
        // Calculate all subarray sums
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                sums[index++] = sum;
            }
        }
        
        // Sort the sums
        Arrays.sort(sums);
        
        // Calculate the range sum
        long result = 0;
        for (int i = left - 1; i < right; i++) {
            result = (result + sums[i]) % MOD;
        }
        
        return (int)result;
    }
}
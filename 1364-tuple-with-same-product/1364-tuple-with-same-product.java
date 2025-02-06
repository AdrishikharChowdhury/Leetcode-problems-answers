class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> productCount = new HashMap<>();
        int n = nums.length;
        
        // Count all possible products of two numbers
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount.put(product, productCount.getOrDefault(product, 0) + 1);
            }
        }
        
        // For each product count k, we can form k*(k-1)/2 pairs of pairs
        // Each pair of pairs can be arranged in 8 ways
        int result = 0;
        for (int count : productCount.values()) {
            if (count > 1) {
                result += 8 * (count * (count - 1) / 2);
            }
        }
        
        return result;
    }
}
class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length;
        int result = n;
        
        // Calculate target remainder
        long total = 0;
        for (int num : nums) {
            total += num;
        }
        
        if (total % p == 0) return 0;
        int target = (int)(total % p);
        
        // Use map to store the latest position of each prefix sum remainder
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum = (int)((currSum + nums[i]) % p);
            // Required remainder to find
            int want = (currSum - target + p) % p;
            if (map.containsKey(want)) {
                result = Math.min(result, i - map.get(want));
            }
            map.put(currSum, i);
        }
        
        return result < n ? result : -1;
    }
}
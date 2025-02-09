import java.util.HashMap;
import java.util.Map;

class Solution {
    public long countBadPairs(int[] nums) {
        int n = nums.length;
        // Calculate total possible pairs
        long totalPairs = ((long) n * (n - 1)) / 2;
        
        // Use a map to count frequencies of nums[i] - i
        Map<Long, Long> freqMap = new HashMap<>();
        
        // Count good pairs (where nums[i] - i == nums[j] - j)
        long goodPairs = 0;
        for (int i = 0; i < n; i++) {
            long diff = nums[i] - (long)i;
            // Add the number of previous elements with same difference
            goodPairs += freqMap.getOrDefault(diff, 0L);
            // Update frequency map
            freqMap.put(diff, freqMap.getOrDefault(diff, 0L) + 1);
        }
        
        // Return total pairs minus good pairs
        return totalPairs - goodPairs;
    }
}
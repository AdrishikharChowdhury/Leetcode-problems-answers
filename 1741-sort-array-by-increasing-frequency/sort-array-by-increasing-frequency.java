import java.util.*;

class Solution {
    public int[] frequencySort(int[] nums) {
        // Count frequencies
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }
        
        // Convert to list of Integer for custom sorting
        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }
        
        // Custom sort
        Collections.sort(list, (a, b) -> {
            int freqCompare = frequencyMap.get(a).compareTo(frequencyMap.get(b));
            if (freqCompare != 0) {
                return freqCompare;
            }
            return b.compareTo(a);
        });
        
        // Convert back to array
        for (int i = 0; i < nums.length; i++) {
            nums[i] = list.get(i);
        }
        
        return nums;
    }
}
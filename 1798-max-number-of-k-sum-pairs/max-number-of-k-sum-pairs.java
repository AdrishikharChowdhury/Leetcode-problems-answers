class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        int operations = 0;
        
        for (int num : nums) {
            int complement = k - num;
            if (frequencyMap.getOrDefault(complement, 0) > 0) {
                operations++;
                frequencyMap.put(complement, frequencyMap.get(complement) - 1);
            } else {
                frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
            }
        }
        
        return operations;
    }
}
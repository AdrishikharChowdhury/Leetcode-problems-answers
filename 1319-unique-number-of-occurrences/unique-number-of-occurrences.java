class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        // Step 1: Count occurrences
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : arr) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        
        // Step 2: Check if counts are unique
        Set<Integer> uniqueCounts = new HashSet<>(countMap.values());
        
        return countMap.size() == uniqueCounts.size();
    }
}
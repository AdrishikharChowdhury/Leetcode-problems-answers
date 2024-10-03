class Solution {
    public int[] arrayRankTransform(int[] arr) {
        // Create a copy of the original array
        int n = arr.length;
        int[] sortedArr = Arrays.copyOf(arr, n);
        
        // Sort the copy
        Arrays.sort(sortedArr);
        
        // Map to store number to rank mapping
        Map<Integer, Integer> rankMap = new HashMap<>();
        int rank = 1;
        
        // Assign ranks to unique numbers
        for (int num : sortedArr) {
            if (!rankMap.containsKey(num)) {
                rankMap.put(num, rank++);
            }
        }
        
        // Transform the original array using ranks
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = rankMap.get(arr[i]);
        }
        
        return result;
    }
}
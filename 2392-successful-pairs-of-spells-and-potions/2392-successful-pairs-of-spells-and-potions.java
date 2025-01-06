class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length;
        int[] pairs = new int[n];
        
        // Sort potions array
        Arrays.sort(potions);
        
        // For each spell, binary search for minimum valid potion
        for (int i = 0; i < n; i++) {
            long spell = spells[i];
            int left = 0, right = m;
            
            while (left < right) {
                int mid = left + (right - left) / 2;
                if ((long)spell * potions[mid] >= success) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            pairs[i] = m - left;
        }
        
        return pairs;
    }
}
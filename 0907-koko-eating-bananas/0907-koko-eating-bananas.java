class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = getMaxPile(piles);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canEatAll(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    private boolean canEatAll(int[] piles, int k, int h) {
        long hoursNeeded = 0;  // Use long to prevent overflow
        for (int pile : piles) {
            // Ceiling division: (pile + k - 1) / k
            hoursNeeded += (pile + k - 1) / k;
        }
        return hoursNeeded <= h;
    }
    
    private int getMaxPile(int[] piles) {
        int max = 0;
        for (int pile : piles) {
            max = Math.max(max, pile);
        }
        return max;
    }
}
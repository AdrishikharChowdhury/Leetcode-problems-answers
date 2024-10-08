class Solution {
    public int minSwaps(String s) {
        // Keep track of unmatched closing brackets
        int unmatched = 0;
        // Keep track of maximum number of unmatched closing brackets
        int maxUnmatched = 0;
        
        // Iterate through the string
        for (char c : s.toCharArray()) {
            if (c == '[') {
                // Opening bracket reduces unmatched count
                unmatched--;
            } else {
                // Closing bracket increases unmatched count
                unmatched++;
            }
            // Update maximum unmatched count
            maxUnmatched = Math.max(unmatched, maxUnmatched);
        }
        
        // The minimum number of swaps needed is (maxUnmatched + 1) / 2
        return (maxUnmatched + 1) / 2;
    }
    
    
}
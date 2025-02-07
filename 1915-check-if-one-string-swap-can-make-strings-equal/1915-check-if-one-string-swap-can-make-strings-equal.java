class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if (s1.equals(s2)) return true;
        
        // Find mismatched positions
        int first = -1, second = -1;
        int mismatches = 0;
        
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                if (mismatches == 0) first = i;
                else if (mismatches == 1) second = i;
                mismatches++;
            }
        }
        
        // Check if exactly two mismatches and characters can be swapped
        return mismatches == 2 && 
               s1.charAt(first) == s2.charAt(second) && 
               s1.charAt(second) == s2.charAt(first);
    }
}
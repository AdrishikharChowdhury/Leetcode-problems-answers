class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        // Count character frequencies
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        
        // StringBuilder for result
        StringBuilder result = new StringBuilder(s.length());
        
        // Start from the largest character
        for (int i = 25; i >= 0; ) {
            // If current character is exhausted, move to next
            if (count[i] == 0) {
                i--;
                continue;
            }
            
            // Determine how many of current character we can add
            int toAdd = Math.min(count[i], 
                result.length() > 0 && (char)(i + 'a') == result.charAt(result.length() - 1) 
                ? repeatLimit - getConsecutiveCount(result) 
                : repeatLimit
            );
            
            // Add current character
            for (int j = 0; j < toAdd; j++) {
                result.append((char)(i + 'a'));
            }
            count[i] -= toAdd;
            
            // If we've added all of current character
            if (count[i] == 0) {
                i--;
                continue;
            }
            
            // Try to break the sequence with a smaller character
            int j = i - 1;
            while (j >= 0 && count[j] == 0) {
                j--;
            }
            
            // If no smaller character available, we're done
            if (j < 0) {
                break;
            }
            
            // Add one smaller character
            result.append((char)(j + 'a'));
            count[j]--;
            
            // If no more of this character, move to next
            if (count[j] == 0) {
                j--;
            }
            
            // Reset where we're looking
            i = Math.max(i, j);
        }
        
        return result.toString();
    }
    
    // Helper method to count consecutive characters at the end
    private int getConsecutiveCount(StringBuilder sb) {
        if (sb.length() == 0) return 0;
        
        char last = sb.charAt(sb.length() - 1);
        int count = 1;
        
        for (int i = sb.length() - 2; i >= 0; i--) {
            if (sb.charAt(i) == last) {
                count++;
            } else {
                break;
            }
        }
        
        return count;
    }
}
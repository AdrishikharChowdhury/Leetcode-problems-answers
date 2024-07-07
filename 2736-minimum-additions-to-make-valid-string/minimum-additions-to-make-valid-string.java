class Solution {
    public int addMinimum(String word) {
        int additions = 0;
        int i = 0;
        char expected = 'a';
        
        while (i < word.length()) {
            if (word.charAt(i) == expected) {
                i++;
            } else {
                additions++;
            }
            
            expected++;
            if (expected > 'c') expected = 'a';
        }
        
        // Add remaining characters to complete the sequence
        while (expected != 'a') {
            additions++;
            expected++;
            if (expected > 'c') expected = 'a';
        }
        
        return additions;
    }
}
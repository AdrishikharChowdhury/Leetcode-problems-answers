class Solution {
    public int maxScore(String s) {
        int maxScore = 0;
        int zeros = 0;
        int ones = 0;
        
        // Count total ones first
        for (char c : s.toCharArray()) {
            if (c == '1') ones++;
        }
        
        // Try each split position except the last one
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '0') {
                zeros++;
            } else {
                ones--;
            }
            maxScore = Math.max(maxScore, zeros + ones);
        }
        
        return maxScore;
    }
}
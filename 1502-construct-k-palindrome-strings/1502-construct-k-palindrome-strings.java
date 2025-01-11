class Solution {
    public boolean canConstruct(String s, int k) {
        // Count frequency of each character
        int[] freq = new int[26];
        
        // If k is greater than string length, impossible
        if (k > s.length()) return false;
        
        // Count frequencies
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        // Count characters with odd frequency
        int oddCount = 0;
        for (int count : freq) {
            if (count % 2 == 1) {
                oddCount++;
            }
        }
        
        // If odd count is greater than k, impossible
        // If k is greater than length, impossible
        // Otherwise, it's possible
        return oddCount <= k && k <= s.length();
    }
}
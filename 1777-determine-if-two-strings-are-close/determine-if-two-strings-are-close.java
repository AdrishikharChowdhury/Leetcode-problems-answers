class Solution {
    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        
        int[] count1 = new int[26];
        int[] count2 = new int[26];
        
        // Count character frequencies
        for (char c : word1.toCharArray()) {
            count1[c - 'a']++;
        }
        for (char c : word2.toCharArray()) {
            count2[c - 'a']++;
        }
        
        // Check if the same characters are present in both strings
        for (int i = 0; i < 26; i++) {
            if ((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0)) {
                return false;
            }
        }
        
        // Sort frequency counts
        Arrays.sort(count1);
        Arrays.sort(count2);
        
        // Compare sorted frequency counts
        return Arrays.equals(count1, count2);
    }
}
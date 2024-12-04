class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int j = 0;
        for (int i = 0; i < str1.length() && j < str2.length(); i++) {
            // Check for direct match or single cyclic increment
            if (str1.charAt(i) == str2.charAt(j) || 
                (char)((str1.charAt(i) - 'a' + 1) % 26 + 'a') == str2.charAt(j)) {
                j++;
            }
        }
        
        // Return true only if all characters in str2 are matched
        return j == str2.length();
    }
}
class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int count = 0;
        
        for (int i = 0; i < words.length; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    private boolean isPrefixAndSuffix(String str1, String str2) {
        // If str1 is longer than str2, it can't be both prefix and suffix
        if (str1.length() > str2.length()) {
            return false;
        }
        
        // Check prefix
        if (!str2.startsWith(str1)) {
            return false;
        }
        
        // Check suffix
        return str2.endsWith(str1);
    }
    
    
}
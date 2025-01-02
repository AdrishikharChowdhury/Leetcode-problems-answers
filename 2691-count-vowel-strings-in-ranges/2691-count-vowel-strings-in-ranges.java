class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length;
        int[] prefixSum = new int[n + 1];
        
        // Build prefix sum array
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + (isVowelString(words[i]) ? 1 : 0);
        }
        
        // Process queries
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            result[i] = prefixSum[right + 1] - prefixSum[left];
        }
        
        return result;
    }
    
    private boolean isVowelString(String s) {
        if (s.isEmpty()) return false;
        return isVowel(s.charAt(0)) && isVowel(s.charAt(s.length() - 1));
    }
    
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
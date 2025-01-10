class Solution {
    // Creates frequency count array for a string
    private int[] getFrequencyCount(String word) {
        int[] freq = new int[26];
        for (char c : word.toCharArray()) {
            freq[c - 'a']++;
        }
        return freq;
    }
    
    public List<String> wordSubsets(String[] words1, String[] words2) {
        // Find maximum frequency required for each character from words2
        int[] maxFreq = new int[26];
        for (String word : words2) {
            int[] freq = getFrequencyCount(word);
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = Math.max(maxFreq[i], freq[i]);
            }
        }
        
        // Check each word in words1
        List<String> result = new ArrayList<>();
        outer: for (String word : words1) {
            int[] freq = getFrequencyCount(word);
            // Check if this word has enough of each required character
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    continue outer;
                }
            }
            result.add(word);
        }
        
        return result;
    }
}
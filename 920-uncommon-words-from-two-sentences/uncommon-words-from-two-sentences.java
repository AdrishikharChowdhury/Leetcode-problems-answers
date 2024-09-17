import java.util.*;

class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> wordCount = new HashMap<>();
        
        // Count words in s1
        for (String word : s1.split(" ")) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }
        
        // Count words in s2
        for (String word : s2.split(" ")) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }
        
        // Find uncommon words
        List<String> uncommonWords = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : wordCount.entrySet()) {
            if (entry.getValue() == 1) {
                uncommonWords.add(entry.getKey());
            }
        }
        
        // Convert list to array
        return uncommonWords.toArray(new String[0]);
    }
}
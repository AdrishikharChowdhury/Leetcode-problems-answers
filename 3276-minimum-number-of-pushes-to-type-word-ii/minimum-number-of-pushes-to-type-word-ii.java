import java.util.*;

class Solution {
    public int minimumPushes(String word) {
        // Count frequency of each character
        int[] freq = new int[26];
        for (char c : word.toCharArray()) {
            freq[c - 'a']++;
        }
        
        // Sort frequencies in descending order
        Integer[] indices = new Integer[26];
        for (int i = 0; i < 26; i++) {
            indices[i] = i;
        }
        Arrays.sort(indices, (a, b) -> freq[b] - freq[a]);
        
        int pushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[indices[i]] == 0) break;
            pushes += freq[indices[i]] * (1 + i / 8);
        }
        
        return pushes;
    }
}
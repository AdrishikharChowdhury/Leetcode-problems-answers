import java.util.*;

class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> frequencyMap = new LinkedHashMap<>();
        
        // Count the frequency of each string
        for (String s : arr) {
            frequencyMap.put(s, frequencyMap.getOrDefault(s, 0) + 1);
        }
        
        // Find the kth distinct string
        int distinctCount = 0;
        for (Map.Entry<String, Integer> entry : frequencyMap.entrySet()) {
            if (entry.getValue() == 1) {
                distinctCount++;
                if (distinctCount == k) {
                    return entry.getKey();
                }
            }
        }
        
        // If there are fewer than k distinct strings
        return "";
    }
}
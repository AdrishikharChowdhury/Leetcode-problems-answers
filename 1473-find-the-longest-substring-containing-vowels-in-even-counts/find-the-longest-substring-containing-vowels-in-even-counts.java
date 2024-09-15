class Solution {
    public int findTheLongestSubstring(String s) {
        String vowels = "aeiou";
        int state = 0;
        Map<Integer, Integer> firstOccurrence = new HashMap<>();
        firstOccurrence.put(0, -1);
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int index = vowels.indexOf(c);
            if (index != -1) {
                state ^= (1 << index);
            }
            
            if (firstOccurrence.containsKey(state)) {
                maxLength = Math.max(maxLength, i - firstOccurrence.get(state));
            } else {
                firstOccurrence.put(state, i);
            }
        }
        
        return maxLength;
    }
}
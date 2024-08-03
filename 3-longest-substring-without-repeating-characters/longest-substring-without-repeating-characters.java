class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLen = 0;
        int start = 0;
        Map<Character, Integer> indexMap = new HashMap<>();

        for (int end = 0; end < n; end++) {
            char currentChar = s.charAt(end);
            if (indexMap.containsKey(currentChar) && indexMap.get(currentChar) >= start) {
                start = indexMap.get(currentChar) + 1;
            }
            indexMap.put(currentChar, end);
            maxLen = Math.max(maxLen, end - start + 1);
        }

        return maxLen;
    }
}
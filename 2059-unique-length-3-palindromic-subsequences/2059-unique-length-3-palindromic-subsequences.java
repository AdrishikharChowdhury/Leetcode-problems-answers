class Solution {
    public int countPalindromicSubsequence(String s) {
        // Store first and last occurrence of each character
        int[] firstOccurrence = new int[26];
        int[] lastOccurrence = new int[26];
        Arrays.fill(firstOccurrence, -1);
        Arrays.fill(lastOccurrence, -1);
        
        // Find first and last occurrence of each character
        for (int i = 0; i < s.length(); i++) {
            int charIndex = s.charAt(i) - 'a';
            if (firstOccurrence[charIndex] == -1) {
                firstOccurrence[charIndex] = i;
            }
            lastOccurrence[charIndex] = i;
        }
        
        int count = 0;
        // For each character as first and last character of palindrome
        for (int i = 0; i < 26; i++) {
            // If character appears at least twice
            if (firstOccurrence[i] != -1 && lastOccurrence[i] > firstOccurrence[i]) {
                // Use Set to count unique characters between first and last occurrence
                Set<Character> middle = new HashSet<>();
                for (int j = firstOccurrence[i] + 1; j < lastOccurrence[i]; j++) {
                    middle.add(s.charAt(j));
                }
                count += middle.size();
            }
        }
        
        return count;
    }
}
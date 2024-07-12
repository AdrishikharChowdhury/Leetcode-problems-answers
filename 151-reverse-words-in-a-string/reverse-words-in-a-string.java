class Solution {
    public String reverseWords(String s) {
        // Split the string by spaces
        String[] words = s.trim().split("\\s+");
        StringBuilder reversed = new StringBuilder();
        
        // Reverse the order of words
        for (int i = words.length - 1; i >= 0; i--) {
            reversed.append(words[i]);
            if (i > 0) {
                reversed.append(" ");
            }
        }
        
        return reversed.toString();
    }
}
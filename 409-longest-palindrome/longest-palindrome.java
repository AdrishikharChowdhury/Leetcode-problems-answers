class Solution {
    public int longestPalindrome(String s) {
        int[] charCount = new int[128];  // Assuming ASCII characters
        
        for (char c : s.toCharArray()) {
            charCount[c]++;
        }
        
        int length = 0;
        boolean hasOdd = false;
        
        for (int count : charCount) {
            length += count / 2 * 2;
            if (count % 2 == 1) {
                hasOdd = true;
            }
        }
        
        return length + (hasOdd ? 1 : 0);
    }
}
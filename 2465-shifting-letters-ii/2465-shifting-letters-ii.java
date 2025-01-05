class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        // Create difference array
        int[] diff = new int[n + 1];
        
        // Process all shifts using difference array
        for (int[] shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            // Convert 0/1 direction to -1/1
            int direction = shift[2] == 1 ? 1 : -1;
            
            diff[start] += direction;
            diff[end + 1] -= direction;
        }
        
        // Calculate prefix sum and apply shifts
        StringBuilder result = new StringBuilder();
        int totalShift = 0;
        
        for (int i = 0; i < n; i++) {
            totalShift += diff[i];
            // Get original character value (0-25)
            int originalVal = s.charAt(i) - 'a';
            // Calculate new value after shift
            int newVal = ((originalVal + totalShift) % 26 + 26) % 26;
            // Convert back to character
            result.append((char)(newVal + 'a'));
        }
        
        return result.toString();
    }
}
class Solution {
    public int takeCharacters(String s, int k) {
        int len = s.length();
        
        // If k is 0, no minutes needed
        if (k == 0) return 0;
        
        // Count total occurrences of a, b, c
        int[] total = new int[3];
        for (char c : s.toCharArray()) {
            total[c - 'a']++;
        }
        
        // If not enough characters
        if (total[0] < k || total[1] < k || total[2] < k) {
            return -1;
        }
        
        // Sliding window to find minimum subarray to remove
        int[] need = new int[]{total[0] - k, total[1] - k, total[2] - k};
        int left = 0, maxRemoved = -1;
        int[] curr = new int[3];
        
        for (int right = 0; right < len; right++) {
            // Add current character to window
            curr[s.charAt(right) - 'a']++;
            
            // Shrink window from left if needed
            while (curr[0] > need[0] || curr[1] > need[1] || curr[2] > need[2]) {
                curr[s.charAt(left) - 'a']--;
                left++;
            }
            
            // Update max removed subarray
            maxRemoved = Math.max(maxRemoved, right - left + 1);
        }
        
        // Total minutes is total length minus max removable subarray
        return len - maxRemoved;
    }
}
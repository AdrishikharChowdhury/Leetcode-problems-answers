class Solution {
    public int minimumLength(String s) {
        int n = s.length();
        // Array to track if character at index i is deleted
        boolean[] deleted = new boolean[n];
        boolean changed;
        
        do {
            changed = false;
            // For each potential center character
            for (int i = 0; i < n; i++) {
                if (deleted[i]) continue;
                
                // Find closest undeleted character to left that matches
                int left = -1;
                for (int j = i - 1; j >= 0; j--) {
                    if (!deleted[j] && s.charAt(j) == s.charAt(i)) {
                        left = j;
                        break;
                    }
                }
                if (left == -1) continue;
                
                // Find closest undeleted character to right that matches
                int right = -1;
                for (int j = i + 1; j < n; j++) {
                    if (!deleted[j] && s.charAt(j) == s.charAt(i)) {
                        right = j;
                        break;
                    }
                }
                if (right == -1) continue;
                
                // Delete the characters
                deleted[left] = true;
                deleted[right] = true;
                changed = true;
            }
        } while (changed);
        
        // Count remaining characters
        int remaining = 0;
        for (int i = 0; i < n; i++) {
            if (!deleted[i]) remaining++;
        }
        
        return remaining;
    }
}
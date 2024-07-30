class Solution {
    public int minimumDeletions(String s) {
        int bCount = 0;
        int deletions = 0;
        
        for (char c : s.toCharArray()) {
            if (c == 'a') {
                if (bCount > 0) {
                    deletions++;
                    bCount--;
                }
            } else {
                bCount++;
            }
        }
        
        return deletions;
    }
}
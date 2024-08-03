class Solution {
    public int equalPairs(int[][] grid) {
        int count = 0;
        int n = grid.length;
        
        // Compare each row with each column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                boolean equal = true;
                for (int k = 0; k < n; k++) {
                    if (grid[i][k] != grid[k][j]) {
                        equal = false;
                        break;
                    }
                }
                if (equal) {
                    count++;
                }
            }
        }
        
        return count;
    }
}
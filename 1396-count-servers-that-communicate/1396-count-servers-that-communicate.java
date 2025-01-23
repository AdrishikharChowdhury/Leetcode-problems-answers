class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        // Count servers in each row and column
        int[] rowCount = new int[m];
        int[] colCount = new int[n];
        
        // First pass: Count servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        // Second pass: Count communicating servers
        int communicatingServers = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Server exists and can communicate if row or column has more than one server
                if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)) {
                    communicatingServers++;
                }
            }
        }
        
        return communicatingServers;
    }
}
class Solution {
    private int time = 0;
    private int[][] grid;
    private int m, n;
    private int[][] dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    public int minDays(int[][] grid) {
        this.grid = grid;
        this.m = grid.length;
        this.n = grid[0].length;
        
        // Check if already disconnected
        if (countIslands() != 1) return 0;
        
        // Check if removing any single cell disconnects the island
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands() != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        // If not, we need to remove 2 cells
        return 2;
    }
    
    private int countIslands() {
        boolean[][] visited = new boolean[m][n];
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
    
    private void dfs(int i, int j, boolean[][] visited) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) return;
        visited[i][j] = true;
        for (int[] d : dir) {
            dfs(i + d[0], j + d[1], visited);
        }
    }
}
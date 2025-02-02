class Solution {
    // Direction arrays for 4-directional movement
    private static final int[] dr = {-1, 1, 0, 0};
    private static final int[] dc = {0, 0, -1, 1};
    private int m, n;
    private int[][] grid;
    private boolean[][] visited;
    
    public int findMaxFish(int[][] grid) {
        this.grid = grid;
        this.m = grid.length;
        this.n = grid[0].length;
        this.visited = new boolean[m][n];
        int maxFish = 0;
        
        // Try starting from each water cell
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] > 0 && !visited[r][c]) {
                    int fishCount = dfs(r, c);
                    maxFish = Math.max(maxFish, fishCount);
                }
            }
        }
        
        return maxFish;
    }
    
    // DFS to count fish in connected water cells
    private int dfs(int r, int c) {
        // Base cases: out of bounds, land cell, or already visited
        if (!isInBounds(r, c) || grid[r][c] == 0 || visited[r][c]) {
            return 0;
        }
        
        // Mark current cell as visited
        visited[r][c] = true;
        int totalFish = grid[r][c];
        
        // Visit all adjacent water cells
        for (int i = 0; i < 4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            totalFish += dfs(newR, newC);
        }
        
        return totalFish;
    }
    
    // Check if cell is within grid bounds
    private boolean isInBounds(int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
}
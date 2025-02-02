class Solution {
    private int n;
    private int[] dr = {-1, 1, 0, 0};
    private int[] dc = {0, 0, -1, 1};
    
    public int largestIsland(int[][] grid) {
        n = grid.length;
        // Map to store island ID -> size
        Map<Integer, Integer> islandSizes = new HashMap<>();
        islandSizes.put(0, 0); // For water cells
        
        // Start island IDs from 2 to avoid confusion with 1s in the grid
        int islandId = 2;
        int maxSize = 0;
        
        // First pass: mark each island with unique ID and get sizes
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    int size = markIsland(grid, r, c, islandId);
                    islandSizes.put(islandId, size);
                    maxSize = Math.max(maxSize, size);
                    islandId++;
                }
            }
        }
        
        // Second pass: try to connect islands by changing one 0 to 1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    // Use set to avoid counting same island multiple times
                    Set<Integer> neighborIslands = new HashSet<>();
                    
                    // Check all 4 directions
                    for (int i = 0; i < 4; i++) {
                        int newR = r + dr[i];
                        int newC = c + dc[i];
                        if (isInBounds(newR, newC)) {
                            neighborIslands.add(grid[newR][newC]);
                        }
                    }
                    
                    // Calculate total size after connecting islands
                    int totalSize = 1; // Include the cell we're changing
                    for (int id : neighborIslands) {
                        totalSize += islandSizes.get(id);
                    }
                    maxSize = Math.max(maxSize, totalSize);
                }
            }
        }
        
        return maxSize;
    }
    
    // DFS to mark an island with given ID and return its size
    private int markIsland(int[][] grid, int r, int c, int id) {
        if (!isInBounds(r, c) || grid[r][c] != 1) {
            return 0;
        }
        
        grid[r][c] = id;
        int size = 1;
        
        // Recursively mark all connected cells
        for (int i = 0; i < 4; i++) {
            size += markIsland(grid, r + dr[i], c + dc[i], id);
        }
        
        return size;
    }
    
    private boolean isInBounds(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
}
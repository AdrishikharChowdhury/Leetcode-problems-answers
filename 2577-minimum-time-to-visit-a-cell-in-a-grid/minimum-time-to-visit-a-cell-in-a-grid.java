class Solution {
    public int minimumTime(int[][] grid) {
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // If the starting point is blocked, return -1
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int m = grid.length, n = grid[0].length;
        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        boolean[][] visited = new boolean[m][n];
        
        heap.offer(new int[]{0, 0, 0}); // (time, row, col)
        
        while (!heap.isEmpty()) {
            int[] curr = heap.poll();
            int time = curr[0], row = curr[1], col = curr[2];
            
            // If we reach the bottom-right corner, return the time
            if (row == m - 1 && col == n - 1) return time;
            
            // Skip if already visited
            if (visited[row][col]) continue;
            visited[row][col] = true;
            
            // Explore all directions
            for (int[] dir : directions) {
                int r = row + dir[0], c = col + dir[1];
                
                // Check bounds and if already visited
                if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {
                    if (grid[r][c] <= time + 1) {
                        heap.offer(new int[]{time + 1, r, c});
                    } else {
                        int diff = grid[r][c] - time;
                        if (diff % 2 == 1) {
                            heap.offer(new int[]{grid[r][c], r, c});
                        } else {
                            heap.offer(new int[]{grid[r][c] + 1, r, c});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
}
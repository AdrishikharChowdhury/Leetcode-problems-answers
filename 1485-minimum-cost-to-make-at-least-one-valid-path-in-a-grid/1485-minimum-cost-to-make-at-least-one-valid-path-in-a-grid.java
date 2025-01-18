class Solution {
    private static final int[][] DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // right, left, down, up
    
    public int minCost(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        // Cost array
        int[][] cost = new int[m][n];
        for (int[] row : cost) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        cost[0][0] = 0;
        
        // PriorityQueue for Dijkstra's algorithm
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        pq.offer(new int[]{0, 0, 0}); // {row, col, cost}
        
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int row = curr[0], col = curr[1], currCost = curr[2];
            
            // Skip if we've found a better path
            if (currCost > cost[row][col]) continue;
            
            // Try all directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + DIRECTIONS[i][0];
                int newCol = col + DIRECTIONS[i][1];
                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    // Calculate new cost based on whether we need to change the arrow
                    int newCost = currCost + (grid[row][col] == i + 1 ? 0 : 1);
                    
                    if (newCost < cost[newRow][newCol]) {
                        cost[newRow][newCol] = newCost;
                        pq.offer(new int[]{newRow, newCol, newCost});
                    }
                }
            }
        }
        
        return cost[m-1][n-1];
    }
}
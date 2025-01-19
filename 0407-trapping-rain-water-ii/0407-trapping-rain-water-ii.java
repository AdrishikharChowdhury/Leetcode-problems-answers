class Solution {
    // Cell class to store height and position information
    private static class Cell implements Comparable<Cell> {
        int height;
        int row;
        int col;
        
        Cell(int height, int row, int col) {
            this.height = height;
            this.row = row;
            this.col = col;
        }
        
        @Override
        public int compareTo(Cell other) {
            return Integer.compare(this.height, other.height);
        }
    }
    
    public int trapRainWater(int[][] heightMap) {
        if (heightMap == null || heightMap.length < 3 || heightMap[0].length < 3)
            return 0;
            
        int m = heightMap.length;
        int n = heightMap[0].length;
        
        // Create priority queue and visited array
        PriorityQueue<Cell> minHeap = new PriorityQueue<>();
        boolean[][] visited = new boolean[m][n];
        
        // Add border cells to priority queue
        // Process first and last rows
        for (int j = 0; j < n; j++) {
            minHeap.offer(new Cell(heightMap[0][j], 0, j));
            minHeap.offer(new Cell(heightMap[m-1][j], m-1, j));
            visited[0][j] = visited[m-1][j] = true;
        }
        
        // Process first and last columns
        for (int i = 1; i < m-1; i++) {
            minHeap.offer(new Cell(heightMap[i][0], i, 0));
            minHeap.offer(new Cell(heightMap[i][n-1], i, n-1));
            visited[i][0] = visited[i][n-1] = true;
        }
        
        // Directions for adjacent cells: up, right, down, left
        int[][] dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        int water = 0;
        int maxBoundary = 0;
        
        // Process cells from lowest to highest
        while (!minHeap.isEmpty()) {
            Cell curr = minHeap.poll();
            maxBoundary = Math.max(maxBoundary, curr.height);
            
            // Check all adjacent cells
            for (int[] dir : dirs) {
                int newRow = curr.row + dir[0];
                int newCol = curr.col + dir[1];
                
                // Skip if out of bounds or already visited
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || 
                    visited[newRow][newCol])
                    continue;
                    
                visited[newRow][newCol] = true;
                
                // If adjacent cell is lower than maxBoundary, it will trap water
                if (heightMap[newRow][newCol] < maxBoundary)
                    water += maxBoundary - heightMap[newRow][newCol];
                    
                // Add adjacent cell to heap
                minHeap.offer(new Cell(heightMap[newRow][newCol], newRow, newCol));
            }
        }
        
        return water;
    }
}
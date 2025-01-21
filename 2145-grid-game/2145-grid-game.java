class Solution {
    // Main solution method
    public long gridGame(int[][] grid) {
        int n = grid[0].length;
        
        // Create prefix sums for both rows
        long[] topSum = new long[n];
        long[] bottomSum = new long[n];
        
        // Calculate prefix sums
        topSum[0] = grid[0][0];
        bottomSum[0] = grid[1][0];
        for (int i = 1; i < n; i++) {
            topSum[i] = topSum[i-1] + grid[0][i];
            bottomSum[i] = bottomSum[i-1] + grid[1][i];
        }
        
        long result = Long.MAX_VALUE;
        // Try each possible turning point for robot 1
        for (int i = 0; i < n; i++) {
            // Calculate remaining points in top row after position i
            long remainingTop = i == n-1 ? 0 : topSum[n-1] - topSum[i];
            
            // Calculate remaining points in bottom row before position i
            long remainingBottom = i == 0 ? 0 : bottomSum[i-1];
            
            // Robot 2 will choose the maximum path
            long robotTwoPoints = Math.max(remainingTop, remainingBottom);
            
            // Robot 1 wants to minimize robot 2's score
            result = Math.min(result, robotTwoPoints);
        }
        
        return result;
    }
}
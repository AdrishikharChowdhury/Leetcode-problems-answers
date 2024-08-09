class Solution {
    private boolean isMagicSquare(int[][] grid, int row, int col) {
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        boolean[] nums = new boolean[10];
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[row+i][col+j];
                if (num < 1 || num > 9 || nums[num]) return false;
                nums[num] = true;
                
                if (grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2] != sum) return false;
                if (grid[row][col+j] + grid[row+1][col+j] + grid[row+2][col+j] != sum) return false;
            }
        }
        
        if (grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != sum) return false;
        if (grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != sum) return false;
        
        return true;
    }
    
    public int numMagicSquaresInside(int[][] grid) {
        int count = 0;
        for (int i = 0; i <= grid.length - 3; i++) {
            for (int j = 0; j <= grid[0].length - 3; j++) {
                if (isMagicSquare(grid, i, j)) count++;
            }
        }
        return count;
    }
}
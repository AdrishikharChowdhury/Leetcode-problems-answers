int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    // Create a grid to mark cells
    int** grid = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        grid[i] = (int*)calloc(n, sizeof(int));
    }
    
    // Mark guards
    for (int i = 0; i < guardsSize; i++) {
        grid[guards[i][0]][guards[i][1]] = 1; // 1 represents guard
    }
    
    // Mark walls
    for (int i = 0; i < wallsSize; i++) {
        grid[walls[i][0]][walls[i][1]] = 2; // 2 represents wall
    }
    
    // Check each guard's visibility
    for (int i = 0; i < guardsSize; i++) {
        int row = guards[i][0], col = guards[i][1];
        
        // Check north
        for (int r = row - 1; r >= 0; r--) {
            if (grid[r][col] == 1 || grid[r][col] == 2) break;
            grid[r][col] = 3; // 3 represents guarded cell
        }
        
        // Check south
        for (int r = row + 1; r < m; r++) {
            if (grid[r][col] == 1 || grid[r][col] == 2) break;
            grid[r][col] = 3;
        }
        
        // Check west
        for (int c = col - 1; c >= 0; c--) {
            if (grid[row][c] == 1 || grid[row][c] == 2) break;
            grid[row][c] = 3;
        }
        
        // Check east
        for (int c = col + 1; c < n; c++) {
            if (grid[row][c] == 1 || grid[row][c] == 2) break;
            grid[row][c] = 3;
        }
    }
    
    // Count unguarded cells
    int unguardedCells = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                unguardedCells++;
            }
        }
    }
    
    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(grid[i]);
    }
    free(grid);
    
    return unguardedCells;
}
int countServers(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // Allocate memory for row and column counts
    int* rowCount = (int*)calloc(m, sizeof(int));
    int* colCount = (int*)calloc(n, sizeof(int));
    
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
    
    // Free allocated memory
    free(rowCount);
    free(colCount);
    
    return communicatingServers;
}
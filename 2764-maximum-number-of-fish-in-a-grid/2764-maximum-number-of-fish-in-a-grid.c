#include <stdio.h>
#include <string.h>

// Direction arrays for 4-directional movement
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

// Check if cell is within grid bounds
bool isInBounds(int r, int c, int m, int n) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

// DFS to count fish in connected water cells
int dfs(int** grid, int m, int n, int r, int c, int** visited) {
    // Base cases: out of bounds, land cell, or already visited
    if (!isInBounds(r, c, m, n) || grid[r][c] == 0 || visited[r][c]) {
        return 0;
    }
    
    // Mark current cell as visited
    visited[r][c] = 1;
    int totalFish = grid[r][c];
    
    // Visit all adjacent water cells
    for (int i = 0; i < 4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        totalFish += dfs(grid, m, n, newR, newC, visited);
    }
    
    return totalFish;
}

int findMaxFish(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int maxFish = 0;
    
    // Create visited array
    int** visited = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        visited[i] = (int*)calloc(n, sizeof(int));
    }
    
    // Try starting from each water cell
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] > 0 && !visited[r][c]) {
                int fishCount = dfs(grid, m, n, r, c, visited);
                maxFish = fishCount > maxFish ? fishCount : maxFish;
            }
        }
    }
    
    // Clean up memory
    for (int i = 0; i < m; i++) {
        free(visited[i]);
    }
    free(visited);
    
    return maxFish;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Direction arrays for 4-directional movement
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

// Function to check if coordinates are within grid bounds
bool isInBounds(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

// DFS to mark an island with given ID and return its size
int markIsland(int** grid, int r, int c, int id, int n) {
    if (!isInBounds(r, c, n) || grid[r][c] != 1) {
        return 0;
    }
    
    grid[r][c] = id;
    int size = 1;
    
    // Recursively mark all connected cells
    for (int i = 0; i < 4; i++) {
        size += markIsland(grid, r + dr[i], c + dc[i], id, n);
    }
    
    return size;
}

int largestIsland(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    
    // Array to store island sizes (using index as ID)
    // Since IDs start from 2, we need space for all possible IDs
    int* islandSizes = (int*)calloc(n * n + 2, sizeof(int));
    int maxSize = 0;
    int islandId = 2;  // Start IDs from 2
    
    // First pass: mark each island with unique ID and get sizes
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 1) {
                int size = markIsland(grid, r, c, islandId, n);
                islandSizes[islandId] = size;
                maxSize = size > maxSize ? size : maxSize;
                islandId++;
            }
        }
    }
    
    // Second pass: try to connect islands by changing one 0 to 1
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 0) {
                // Use array to track which islands we've counted
                int neighborIds[4] = {0};  // Store up to 4 unique neighbor IDs
                int idCount = 0;
                
                // Check all 4 directions
                for (int i = 0; i < 4; i++) {
                    int newR = r + dr[i];
                    int newC = c + dc[i];
                    
                    if (isInBounds(newR, newC, n)) {
                        int currId = grid[newR][newC];
                        // Check if we haven't counted this island yet
                        bool isNewId = true;
                        for (int j = 0; j < idCount; j++) {
                            if (neighborIds[j] == currId) {
                                isNewId = false;
                                break;
                            }
                        }
                        if (isNewId && currId != 0) {
                            neighborIds[idCount++] = currId;
                        }
                    }
                }
                
                // Calculate total size after connecting islands
                int totalSize = 1;  // Include the cell we're changing
                for (int i = 0; i < idCount; i++) {
                    totalSize += islandSizes[neighborIds[i]];
                }
                maxSize = totalSize > maxSize ? totalSize : maxSize;
            }
        }
    }
    
    free(islandSizes);
    return maxSize;
}
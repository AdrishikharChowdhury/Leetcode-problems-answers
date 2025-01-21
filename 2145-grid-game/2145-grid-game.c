#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

long long gridGame(int** grid, int gridSize, int* gridColSize) {
    int n = gridColSize[0];
    
    // Allocate memory for prefix sums
    long long* topSum = (long long*)malloc(n * sizeof(long long));
    long long* bottomSum = (long long*)malloc(n * sizeof(long long));
    
    // Calculate prefix sums
    topSum[0] = grid[0][0];
    bottomSum[0] = grid[1][0];
    for (int i = 1; i < n; i++) {
        topSum[i] = topSum[i-1] + grid[0][i];
        bottomSum[i] = bottomSum[i-1] + grid[1][i];
    }
    
    long long result = LLONG_MAX;
    // Try each possible turning point for robot 1
    for (int i = 0; i < n; i++) {
        // Calculate remaining points in top row after position i
        long long remainingTop = (i == n-1) ? 0 : topSum[n-1] - topSum[i];
        
        // Calculate remaining points in bottom row before position i
        long long remainingBottom = (i == 0) ? 0 : bottomSum[i-1];
        
        // Robot 2 will choose the maximum path
        long long robotTwoPoints = MAX(remainingTop, remainingBottom);
        
        // Robot 1 wants to minimize robot 2's score
        result = MIN(result, robotTwoPoints);
    }
    
    // Free allocated memory
    free(topSum);
    free(bottomSum);
    
    return result;
}

// Helper function to create 2D array
int** createGrid(int rows, int cols) {
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
    }
    return grid;
}

// Helper function to free 2D array
void freeGrid(int** grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

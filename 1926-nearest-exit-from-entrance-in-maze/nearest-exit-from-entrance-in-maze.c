#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a cell in the queue
typedef struct {
    int row;
    int col;
    int steps;
} Cell;

// Function to check if a cell is a valid exit
bool isExit(int row, int col, int m, int n, int entranceRow, int entranceCol) {
    return (row == 0 || row == m - 1 || col == 0 || col == n - 1) &&
           (row != entranceRow || col != entranceCol);
}

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    int m = mazeSize;
    int n = mazeColSize[0];
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
    
    // Create a queue for BFS
    Cell* queue = (Cell*)malloc(m * n * sizeof(Cell));
    int front = 0, rear = 0;
    
    // Enqueue the entrance cell
    queue[rear++] = (Cell){entrance[0], entrance[1], 0};
    
    // Create a visited array
    bool** visited = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        visited[i] = (bool*)calloc(n, sizeof(bool));
    }
    visited[entrance[0]][entrance[1]] = true;
    
    while (front < rear) {
        Cell current = queue[front++];
        
        // Check if current cell is an exit
        if (isExit(current.row, current.col, m, n, entrance[0], entrance[1])) {
            // Free allocated memory before returning
            free(queue);
            for (int i = 0; i < m; i++) {
                free(visited[i]);
            }
            free(visited);
            return current.steps;
        }
        
        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + directions[i][0];
            int newCol = current.col + directions[i][1];
            
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                maze[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                queue[rear++] = (Cell){newRow, newCol, current.steps + 1};
                visited[newRow][newCol] = true;
            }
        }
    }
    
    // Free allocated memory before returning
    free(queue);
    for (int i = 0; i < m; i++) {
        free(visited[i]);
    }
    free(visited);
    
    return -1; // No exit found
}
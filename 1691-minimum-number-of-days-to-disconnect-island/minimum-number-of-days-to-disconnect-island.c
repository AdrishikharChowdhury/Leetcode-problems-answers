#define MAX_SIZE 30
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int m, n;
int grid[MAX_SIZE][MAX_SIZE];
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void dfs(int i, int j, int visited[MAX_SIZE][MAX_SIZE]);
int countIslands();  // Add this function prototype

int minDays(int** input_grid, int gridSize, int* gridColSize) {
    m = gridSize;
    n = gridColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = input_grid[i][j];
        }
    }
    
    // Check if already disconnected
    if (countIslands() != 1) return 0;
    
    // Check if removing any single cell disconnects the island
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                if (countIslands() != 1) {
                    grid[i][j] = 1;
                    return 1;
                }
                grid[i][j] = 1;
            }
        }
    }
    
    // If not, we need to remove 2 cells
    return 2;
}

void dfs(int i, int j, int visited[MAX_SIZE][MAX_SIZE]) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) return;
    visited[i][j] = 1;
    for (int d = 0; d < 4; d++) {
        dfs(i + dir[d][0], j + dir[d][1], visited);
    }
}

int countIslands() {
    int visited[MAX_SIZE][MAX_SIZE] = {0};
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, visited);
                count++;
            }
        }
    }
    return count;
}
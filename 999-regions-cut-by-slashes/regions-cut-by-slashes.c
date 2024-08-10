#define MAX_SIZE 30*30*4

int parent[MAX_SIZE];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int getIndex(int n, int row, int col, int pos) {
    return 4 * (row * n + col) + pos;
}

int regionsBySlashes(char ** grid, int gridSize){
    int n = gridSize;
    int count = 4 * n * n;
    
    for (int i = 0; i < count; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) unionSet(getIndex(n, i-1, j, 2), getIndex(n, i, j, 0));
            if (j > 0) unionSet(getIndex(n, i, j-1, 1), getIndex(n, i, j, 3));
            
            if (grid[i][j] != '/') {
                unionSet(getIndex(n, i, j, 0), getIndex(n, i, j, 1));
                unionSet(getIndex(n, i, j, 2), getIndex(n, i, j, 3));
            }
            if (grid[i][j] != '\\') {
                unionSet(getIndex(n, i, j, 0), getIndex(n, i, j, 3));
                unionSet(getIndex(n, i, j, 1), getIndex(n, i, j, 2));
            }
        }
    }
    
    int regions = 0;
    for (int i = 0; i < count; i++) {
        if (find(i) == i) {
            regions++;
        }
    }
    
    return regions;
}
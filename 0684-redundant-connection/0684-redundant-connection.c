int find(int parent[], int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]); // Path compression
    }
    return parent[x];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Initialize parent and rank arrays
    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));
    int* rank = (int*)calloc(edgesSize + 1, sizeof(int));
    
    // Initialize each node as its own parent
    for (int i = 0; i <= edgesSize; i++) {
        parent[i] = i;
    }
    
    // Process each edge
    for (int i = 0; i < edgesSize; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        
        // If vertices are already in the same set, we found our redundant edge
        if (find(parent, x) == find(parent, y)) {
            result[0] = x;
            result[1] = y;
        } else {
            unionSets(parent, rank, x, y);
        }
    }
    
    free(parent);
    free(rank);
    return result;
}
int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize) {
    int* status = calloc(graphSize, sizeof(int));
    int* safeNodes = malloc(graphSize * sizeof(int));
    *returnSize = 0;
    
    bool dfs(int node) {
        if (status[node] != 0) {
            return status[node] == 2;
        }
        
        status[node] = 1;  // Visiting
        
        for (int i = 0; i < graphColSize[node]; i++) {
            int neighbor = graph[node][i];
            if (status[neighbor] == 1 || !dfs(neighbor)) {
                status[node] = 3;  // Unsafe
                return false;
            }
        }
        
        status[node] = 2;  // Safe
        return true;
    }
    
    for (int i = 0; i < graphSize; i++) {
        if (dfs(i)) {
            safeNodes[(*returnSize)++] = i;
        }
    }
    
    // Sort safe nodes
    for (int i = 0; i < *returnSize - 1; i++) {
        for (int j = 0; j < *returnSize - i - 1; j++) {
            if (safeNodes[j] > safeNodes[j+1]) {
                int temp = safeNodes[j];
                safeNodes[j] = safeNodes[j+1];
                safeNodes[j+1] = temp;
            }
        }
    }
    
    free(status);
    return safeNodes;
}
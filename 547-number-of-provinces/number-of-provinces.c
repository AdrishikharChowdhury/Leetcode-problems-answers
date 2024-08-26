void dfs(int** isConnected, int* visited, int city, int n) {
    visited[city] = 1;
    for (int neighbor = 0; neighbor < n; neighbor++) {
        if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
            dfs(isConnected, visited, neighbor, n);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int* visited = (int*)calloc(n, sizeof(int));
    int provinces = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, i, n);
            provinces++;
        }
    }
    
    free(visited);
    return provinces;
}
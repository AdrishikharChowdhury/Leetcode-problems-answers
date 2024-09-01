struct Edge {
    int to;
    int original;
};

void dfs(int city, struct Edge** graph, int* sizes, bool* visited, int* count) {
    visited[city] = true;
    
    for (int i = 0; i < sizes[city]; i++) {
        struct Edge neighbor = graph[city][i];
        if (!visited[neighbor.to]) {
            *count += neighbor.original;
            dfs(neighbor.to, graph, sizes, visited, count);
        }
    }
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    struct Edge** graph = (struct Edge**)malloc(n * sizeof(struct Edge*));
    int* sizes = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < connectionsSize; i++) {
        sizes[connections[i][0]]++;
        sizes[connections[i][1]]++;
    }
    
    for (int i = 0; i < n; i++) {
        graph[i] = (struct Edge*)malloc(sizes[i] * sizeof(struct Edge));
        sizes[i] = 0;
    }
    
    for (int i = 0; i < connectionsSize; i++) {
        int a = connections[i][0], b = connections[i][1];
        graph[a][sizes[a]++] = (struct Edge){b, 1};
        graph[b][sizes[b]++] = (struct Edge){a, 0};
    }
    
    bool* visited = (bool*)calloc(n, sizeof(bool));
    int count = 0;
    
    dfs(0, graph, sizes, visited, &count);
    
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(sizes);
    free(visited);
    
    return count;
}
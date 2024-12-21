void addEdge(int** adj, int* sizes, int u, int v) {
    adj[u][sizes[u]++] = v;
    adj[v][sizes[v]++] = u;
}

long long dfs(int node, int parent, int* values, int** adj, int* sizes, int k, int* components) {
    long long sum = values[node];
    
    // Process all children
    for (int i = 0; i < sizes[node]; i++) {
        int child = adj[node][i];
        if (child != parent) {
            sum += dfs(child, node, values, adj, sizes, k, components);
        }
    }
    
    // If divisible by k, increment components
    if (sum % k == 0) {
        (*components)++;
        return 0;
    }
    
    return sum;
}

int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, 
                          int* values, int valuesSize, int k) {
    // Allocate memory for adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* sizes = (int*)calloc(n, sizeof(int));
    
    // First pass to count neighbors
    for (int i = 0; i < edgesSize; i++) {
        sizes[edges[i][0]]++;
        sizes[edges[i][1]]++;
    }
    
    // Allocate memory for each vertex's neighbors
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(sizes[i] * sizeof(int));
        sizes[i] = 0;  // Reset sizes for second pass
    }
    
    // Second pass to build adjacency list
    for (int i = 0; i < edgesSize; i++) {
        addEdge(adj, sizes, edges[i][0], edges[i][1]);
    }
    
    int components = 0;
    dfs(0, -1, values, adj, sizes, k, &components);
    
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(sizes);
    
    return components;
}
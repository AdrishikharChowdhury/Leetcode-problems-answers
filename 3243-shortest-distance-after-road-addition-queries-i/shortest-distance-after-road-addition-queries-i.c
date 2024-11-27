int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Allocate graph adjacency list
    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphSizes = (int*)calloc(n, sizeof(int));
    int* graphCapacities = (int*)malloc(n * sizeof(int));
    
    // Initial direct connections
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        graphCapacities[i] = n;
        
        if (i < n - 1) {
            graph[i][graphSizes[i]++] = i + 1;
        }
    }
    
    // Allocate result array
    int* answer = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    // BFS helper function
    int bfs(int n, int** graph, int* graphSizes) {
        // Distance array
        int* dist = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX;
        }
        
        // Queue for BFS
        int* queue = (int*)malloc(n * sizeof(int));
        int front = 0, rear = 0;
        
        // Start from city 0
        queue[rear++] = 0;
        dist[0] = 0;
        
        while (front < rear) {
            int current = queue[front++];
            
            // Reached destination
            if (current == n - 1) {
                int shortestPath = dist[n - 1];
                free(dist);
                free(queue);
                return shortestPath;
            }
            
            // Explore neighbors
            for (int i = 0; i < graphSizes[current]; i++) {
                int neighbor = graph[current][i];
                if (dist[neighbor] > dist[current] + 1) {
                    dist[neighbor] = dist[current] + 1;
                    queue[rear++] = neighbor;
                }
            }
        }
        
        free(dist);
        free(queue);
        return -1; // No path found
    }
    
    // Process each query
    for (int i = 0; i < queriesSize; i++) {
        int ui = queries[i][0];
        int vi = queries[i][1];
        
        // Add new road
        graph[ui][graphSizes[ui]++] = vi;
        
        // Find shortest path
        answer[i] = bfs(n, graph, graphSizes);
    }
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(graphSizes);
    free(graphCapacities);
    
    return answer;
}
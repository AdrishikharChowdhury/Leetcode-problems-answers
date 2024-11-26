int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
    // Track incoming edges for each node
    int* incomingEdges = (int*)calloc(n, sizeof(int));
    
    // Count incoming edges for each node
    for (int i = 0; i < edgesSize; i++) {
        incomingEdges[edges[i][1]]++;
    }
    
    // Find nodes with no incoming edges
    int championCount = 0;
    int champion = -1;
    
    for (int i = 0; i < n; i++) {
        if (incomingEdges[i] == 0) {
            championCount++;
            champion = i;
        }
    }
    
    // Free allocated memory
    free(incomingEdges);
    
    // Return champion if unique, else -1
    return championCount == 1 ? champion : -1;
}
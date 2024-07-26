#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX_CITIES 100
#define INF 10000000

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int dist[MAX_CITIES][MAX_CITIES];
    
    // Initialize distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }
    
    // Build initial distance matrix from edges
    for (int i = 0; i < edgesSize; i++) {
        int from = edges[i][0], to = edges[i][1], weight = edges[i][2];
        dist[from][to] = dist[to][from] = weight;
    }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int minReachableCities = n;
    int result = -1;
    
    // Count reachable cities for each city
    for (int i = 0; i < n; i++) {
        int reachableCities = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                reachableCities++;
            }
        }
        if (reachableCities <= minReachableCities) {
            minReachableCities = reachableCities;
            result = i;
        }
    }
    
    return result;
}
class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // Initialize distance matrix
        int[][] dist = new int[n][n];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE / 2); // Avoid overflow
        }
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        // Build initial distance matrix from edges
        for (int[] edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            dist[from][to] = dist[to][from] = weight;
        }
        
        // Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
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
}
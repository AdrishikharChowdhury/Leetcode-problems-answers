class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        // Initialize graph as an adjacency list
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        
        // Initial direct connections
        for (int i = 0; i < n - 1; i++) {
            graph.get(i).add(i + 1);
        }
        
        // Result array to store shortest path lengths
        int[] answer = new int[queries.length];
        
        // Process each query
        for (int i = 0; i < queries.length; i++) {
            // Add new road from ui to vi
            int ui = queries[i][0];
            int vi = queries[i][1];
            graph.get(ui).add(vi);
            
            // Find shortest path using BFS
            answer[i] = bfs(n, graph);
        }
        
        return answer;
    }
     private int bfs(int n, List<List<Integer>> graph) {
        // Queue for BFS traversal
        Queue<Integer> queue = new LinkedList<>();
        // Distance array to track shortest distances
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        // Start from city 0
        queue.offer(0);
        dist[0] = 0;
        
        while (!queue.isEmpty()) {
            int current = queue.poll();
            
            // If reached destination
            if (current == n - 1) {
                return dist[n - 1];
            }
            
            // Explore neighbors
            for (int neighbor : graph.get(current)) {
                if (dist[neighbor] > dist[current] + 1) {
                    dist[neighbor] = dist[current] + 1;
                    queue.offer(neighbor);
                }
            }
        }
        
        return -1; // No path found
    }
}
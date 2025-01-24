class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        int[] status = new int[n];
        List<Integer> safeNodes = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            if (dfs(graph, i, status)) {
                safeNodes.add(i);
            }
        }
        
        Collections.sort(safeNodes);
        return safeNodes;
    }
    
    private boolean dfs(int[][] graph, int node, int[] status) {
        // 0: unvisited, 1: visiting, 2: safe, 3: unsafe
        if (status[node] != 0) {
            return status[node] == 2;
        }
        
        status[node] = 1;  // Mark as visiting
        
        for (int neighbor : graph[node]) {
            if (status[neighbor] == 1 || !dfs(graph, neighbor, status)) {
                status[node] = 3;  // Unsafe path found
                return false;
            }
        }
        
        status[node] = 2;  // Safe node
        return true;
    }
}
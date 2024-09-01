class Solution {
    private List<List<int[]>> graph;
    private boolean[] visited;
    private int count;

    public int minReorder(int n, int[][] connections) {
        graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] conn : connections) {
            graph.get(conn[0]).add(new int[]{conn[1], 1}); // Original edge
            graph.get(conn[1]).add(new int[]{conn[0], 0}); // Reverse edge
        }
        
        visited = new boolean[n];
        count = 0;
        
        dfs(0);
        
        return count;
    }
    
    private void dfs(int city) {
        visited[city] = true;
        
        for (int[] neighbor : graph.get(city)) {
            if (!visited[neighbor[0]]) {
                count += neighbor[1]; // If it's an original edge, increment count
                dfs(neighbor[0]);
            }
        }
    }
}
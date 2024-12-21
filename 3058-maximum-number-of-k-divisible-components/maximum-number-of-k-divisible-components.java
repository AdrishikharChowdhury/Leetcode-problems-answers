class Solution {
    // Lists to store the adjacency list representation of the tree
    private List<Integer>[] adj;
    private int[] values;
    private int k;
    private int components;

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        this.values = values;
        this.k = k;
        this.components = 0;
        
        // Initialize adjacency list
        adj = new List[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        // Build undirected tree
        for (int[] edge : edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }
        
        // Start DFS from root (0)
        dfs(0, -1);
        
        return components;
    }
    
    // Returns sum of values in subtree
    private long dfs(int node, int parent) {
        long sum = values[node];
        
        // Process all children except parent
        for (int child : adj[node]) {
            if (child != parent) {
                sum += dfs(child, node);
            }
        }
        
        // If sum is divisible by k, we can make this a separate component
        if (sum % k == 0) {
            components++;
            return 0;
        }
        
        return sum;
    }
}
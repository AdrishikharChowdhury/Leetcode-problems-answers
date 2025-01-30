class Solution {
    private List<List<Integer>> graph;
    private Set<Integer> visited;
    private int[] group;
    
    public int magnificentSets(int n, int[][] edges) {
        // Build adjacency list representation of the graph
        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        
        // Track visited nodes and their group assignments
        visited = new HashSet<>();
        group = new int[n + 1];
        int result = 0;
        
        // Process each connected component separately
        for (int i = 1; i <= n; i++) {
            if (!visited.contains(i)) {
                // Get all nodes in current component
                List<Integer> component = new ArrayList<>();
                dfs(i, component);
                
                // Find maximum groups possible for this component
                int maxGroups = -1;
                for (int node : component) {
                    int groups = bfs(node, n);
                    if (groups == -1) {
                        return -1;  // Impossible to group
                    }
                    maxGroups = Math.max(maxGroups, groups);
                }
                result += maxGroups;
            }
        }
        
        return result;
    }
    
    // DFS to find connected components
    private void dfs(int node, List<Integer> component) {
        visited.add(node);
        component.add(node);
        
        for (int neighbor : graph.get(node)) {
            if (!visited.contains(neighbor)) {
                dfs(neighbor, component);
            }
        }
    }
    
    // BFS to find maximum groups starting from a node
    private int bfs(int start, int n) {
        Queue<Integer> queue = new LinkedList<>();
        Map<Integer, Integer> distance = new HashMap<>();
        
        queue.offer(start);
        distance.put(start, 1);  // Start with group 1
        int maxGroup = 1;
        
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            int currGroup = distance.get(curr);
            maxGroup = Math.max(maxGroup, currGroup);
            
            for (int neighbor : graph.get(curr)) {
                if (!distance.containsKey(neighbor)) {
                    distance.put(neighbor, currGroup + 1);
                    queue.offer(neighbor);
                } else if (Math.abs(distance.get(neighbor) - currGroup) != 1) {
                    return -1;  // Invalid grouping found
                }
            }
        }
        
        return maxGroup;
    }
}
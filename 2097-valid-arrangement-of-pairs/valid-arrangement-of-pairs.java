import java.util.*;

class Solution {
    private Map<Integer, List<Integer>> graph;
    private Map<Integer, Integer> inDegree;
    private Map<Integer, Integer> outDegree;
    private List<Integer> path;

    public int[][] validArrangement(int[][] pairs) {
        // Build graph and track in/out degrees
        buildGraph(pairs);

        // Find starting node
        int start = findStartNode();

        // Hierholzer's algorithm for Eulerian path
        path = new ArrayList<>();
        if (start != -1) {
            dfs(start);
        } else {
            dfs(pairs[0][0]);
        }
        
        // Reverse the path and convert to result
        Collections.reverse(path);
        int[][] result = new int[pairs.length][2];
        
        for (int i = 0; i < path.size() - 1; i++) {
            result[i][0] = path.get(i);
            result[i][1] = path.get(i + 1);
        }
        
        return result;
    }

    private void buildGraph(int[][] pairs) {
        graph = new HashMap<>();
        inDegree = new HashMap<>();
        outDegree = new HashMap<>();

        // Initialize graph and degree tracking
        for (int[] pair : pairs) {
            graph.putIfAbsent(pair[0], new ArrayList<>());
            graph.get(pair[0]).add(pair[1]);

            outDegree.put(pair[0], outDegree.getOrDefault(pair[0], 0) + 1);
            inDegree.put(pair[1], inDegree.getOrDefault(pair[1], 0) + 1);
            
            // Ensure nodes exist in both maps
            inDegree.putIfAbsent(pair[0], 0);
            outDegree.putIfAbsent(pair[1], 0);
        }
    }

    private int findStartNode() {
        // Find a node with out-degree one more than in-degree
        for (int node : graph.keySet()) {
            if (outDegree.get(node) - inDegree.get(node) == 1) {
                return node;
            }
        }
        // If no such node, return any node in the graph
        return graph.isEmpty() ? -1 : graph.keySet().iterator().next();
    }

    private void dfs(int node) {
        while (graph.containsKey(node) && !graph.get(node).isEmpty()) {
            int next = graph.get(node).remove(graph.get(node).size() - 1);
            dfs(next);
        }
        path.add(node);
    }
}
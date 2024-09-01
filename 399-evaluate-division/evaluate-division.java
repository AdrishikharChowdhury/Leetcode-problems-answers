import java.util.*;

class Solution {
    private Map<String, Map<String, Double>> graph;

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        graph = buildGraph(equations, values);
        double[] results = new double[queries.size()];
        
        for (int i = 0; i < queries.size(); i++) {
            String start = queries.get(i).get(0);
            String end = queries.get(i).get(1);
            results[i] = dfs(start, end, new HashSet<>());
        }
        
        return results;
    }
    
    private Map<String, Map<String, Double>> buildGraph(List<List<String>> equations, double[] values) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        
        for (int i = 0; i < equations.size(); i++) {
            String u = equations.get(i).get(0);
            String v = equations.get(i).get(1);
            double value = values[i];
            
            graph.putIfAbsent(u, new HashMap<>());
            graph.putIfAbsent(v, new HashMap<>());
            graph.get(u).put(v, value);
            graph.get(v).put(u, 1 / value);
        }
        
        return graph;
    }
    
    private double dfs(String start, String end, Set<String> visited) {
        if (!graph.containsKey(start)) return -1.0;
        if (start.equals(end)) return 1.0;
        
        visited.add(start);
        
        for (Map.Entry<String, Double> neighbor : graph.get(start).entrySet()) {
            if (!visited.contains(neighbor.getKey())) {
                double result = dfs(neighbor.getKey(), end, visited);
                if (result != -1.0) {
                    return result * neighbor.getValue();
                }
            }
        }
        
        visited.remove(start);
        return -1.0;
    }
}
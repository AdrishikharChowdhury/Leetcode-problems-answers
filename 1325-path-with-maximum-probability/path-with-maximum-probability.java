class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        // Create adjacency list
        List<List<Pair<Integer, Double>>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < edges.length; i++) {
            int a = edges[i][0], b = edges[i][1];
            double prob = succProb[i];
            adj.get(a).add(new Pair<>(b, prob));
            adj.get(b).add(new Pair<>(a, prob));
        }
        
        // Dijkstra's algorithm
        double[] maxProb = new double[n];
        maxProb[start] = 1.0;
        
        PriorityQueue<Pair<Integer, Double>> pq = new PriorityQueue<>((a, b) -> Double.compare(b.getValue(), a.getValue()));
        pq.offer(new Pair<>(start, 1.0));
        
        while (!pq.isEmpty()) {
            Pair<Integer, Double> curr = pq.poll();
            int node = curr.getKey();
            double prob = curr.getValue();
            
            if (node == end) return prob;
            
            if (prob < maxProb[node]) continue;
            
            for (Pair<Integer, Double> neighbor : adj.get(node)) {
                int nextNode = neighbor.getKey();
                double newProb = prob * neighbor.getValue();
                if (newProb > maxProb[nextNode]) {
                    maxProb[nextNode] = newProb;
                    pq.offer(new Pair<>(nextNode, newProb));
                }
            }
        }
        
        return 0.0;
    }
}
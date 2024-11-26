class Solution {
    public int findChampion(int n, int[][] edges) {
        // Track incoming edges for each node
        int[] incomingEdges = new int[n];
        
        // Count incoming edges for each node
        for (int[] edge : edges) {
            incomingEdges[edge[1]]++;
        }
        
        // Find nodes with no incoming edges
        int championCount = 0;
        int champion = -1;
        
        for (int i = 0; i < n; i++) {
            if (incomingEdges[i] == 0) {
                championCount++;
                champion = i;
            }
        }
        
        // Return champion if unique, else -1
        return championCount == 1 ? champion : -1;
    }
}
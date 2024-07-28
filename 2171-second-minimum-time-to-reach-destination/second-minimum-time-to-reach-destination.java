import java.util.*;

class Solution {
    public int secondMinimum(int n, int[][] edges, int time, int change) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        
        int[][] dist = new int[n+1][2];
        for (int i = 1; i <= n; i++) {
            dist[i][0] = dist[i][1] = Integer.MAX_VALUE;
        }
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{1, 0});
        dist[1][0] = 0;
        
        while (!pq.isEmpty()) {
            int[] node = pq.poll();
            int u = node[0], t = node[1];
            
            if (u == n && t > dist[n][0]) return t;
            
            int wait = ((t / change) % 2 == 0) ? 0 : change - (t % change);
            int newTime = t + wait + time;
            
            for (int v : graph.get(u)) {
                if (newTime < dist[v][0]) {
                    dist[v][1] = dist[v][0];
                    dist[v][0] = newTime;
                    pq.offer(new int[]{v, newTime});
                } else if (newTime > dist[v][0] && newTime < dist[v][1]) {
                    dist[v][1] = newTime;
                    pq.offer(new int[]{v, newTime});
                }
            }
        }
        
        return -1;
    }
}
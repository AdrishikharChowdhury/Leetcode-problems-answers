import java.util.*;

class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        int[][] pairs = new int[n][2];
        for (int i = 0; i < n; i++) {
            pairs[i] = new int[]{nums1[i], nums2[i]};
        }
        Arrays.sort(pairs, (a, b) -> b[1] - a[1]);
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(k);
        long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += pairs[i][0];
            pq.offer(pairs[i][0]);
        }
        
        long maxScore = sum * pairs[k-1][1];
        
        for (int i = k; i < n; i++) {
            sum += pairs[i][0] - pq.poll();
            pq.offer(pairs[i][0]);
            maxScore = Math.max(maxScore, sum * pairs[i][1]);
        }
        
        return maxScore;
    }
}
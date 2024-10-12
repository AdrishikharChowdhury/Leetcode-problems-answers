import java.util.*;

class Solution {
    public int minGroups(int[][] intervals) {
        // Sort intervals based on start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        
        // Min heap to keep track of end times of groups
        PriorityQueue<Integer> endTimes = new PriorityQueue<>();
        
        for (int[] interval : intervals) {
            if (!endTimes.isEmpty() && endTimes.peek() < interval[0]) {
                // If the current interval starts after the earliest end time,
                // we can reuse that group
                endTimes.poll();
            }
            // Add the end time of the current interval
            endTimes.offer(interval[1]);
        }
        
        // The size of the heap is the minimum number of groups needed
        return endTimes.size();
    }

    
}
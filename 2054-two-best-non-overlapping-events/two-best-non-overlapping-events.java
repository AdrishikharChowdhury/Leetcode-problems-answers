class Solution {
    public int maxTwoEvents(int[][] events) {
        // Sort events by start time
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        
        int n = events.length;
        int maxValue = 0;
        
        // Maintain max value seen so far from the right
        int[] maxFromRight = new int[n];
        maxFromRight[n-1] = events[n-1][2];
        
        for (int i = n-2; i >= 0; i--) {
            maxFromRight[i] = Math.max(maxFromRight[i+1], events[i][2]);
        }
        
        // For each event, find the maximum value of a non-overlapping event
        for (int i = 0; i < n; i++) {
            // Current event value
            int currValue = events[i][2];
            maxValue = Math.max(maxValue, currValue);
            
            // Find max value for a non-overlapping event
            int j = binarySearch(events, i);
            if (j != -1) {
                maxValue = Math.max(maxValue, currValue + maxFromRight[j]);
            }
        }
        
        return maxValue;
    }
    
    // Binary search to find the first event that starts after the current event ends
    private int binarySearch(int[][] events, int currentIndex) {
        int targetEnd = events[currentIndex][1];
        int left = currentIndex + 1;
        int right = events.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (events[mid][0] > targetEnd) {
                // If this is the first such event, or the previous event overlaps
                if (mid == left || events[mid-1][0] <= targetEnd) {
                    return mid;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return -1;
    }
}
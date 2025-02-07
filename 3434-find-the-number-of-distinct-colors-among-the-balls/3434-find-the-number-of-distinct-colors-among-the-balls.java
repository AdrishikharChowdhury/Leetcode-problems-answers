class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        int n = queries.length;
        int[] result = new int[n];
        
        // Map to store ball -> color assignments
        Map<Integer, Integer> ballColors = new HashMap<>();
        // Map to store color -> count of balls with that color
        Map<Integer, Integer> colorCounts = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int newColor = queries[i][1];
            
            // Remove old color if ball was previously colored
            if (ballColors.containsKey(ball)) {
                int oldColor = ballColors.get(ball);
                int count = colorCounts.get(oldColor);
                if (count == 1) {
                    colorCounts.remove(oldColor);
                } else {
                    colorCounts.put(oldColor, count - 1);
                }
            }
            
            // Assign new color
            ballColors.put(ball, newColor);
            colorCounts.put(newColor, colorCounts.getOrDefault(newColor, 0) + 1);
            
            // Store distinct color count
            result[i] = colorCounts.size();
        }
        
        return result;
    }
}
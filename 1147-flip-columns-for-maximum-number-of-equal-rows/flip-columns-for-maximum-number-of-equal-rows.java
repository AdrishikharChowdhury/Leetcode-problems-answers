class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> patternCount = new HashMap<>();
        int maxEqualRows = 0;
        
        for (int[] row : matrix) {
            // Create two possible patterns: original and flipped
            StringBuilder original = new StringBuilder();
            StringBuilder flipped = new StringBuilder();
            
            for (int cell : row) {
                original.append(cell);
                flipped.append(1 - cell);
            }
            
            // Generate pattern string
            String pattern = original.toString();
            String flippedPattern = flipped.toString();
            
            // Choose lexicographically smaller pattern
            String key = pattern.compareTo(flippedPattern) <= 0 ? pattern : flippedPattern;
            
            // Count pattern occurrences
            patternCount.put(key, patternCount.getOrDefault(key, 0) + 1);
            maxEqualRows = Math.max(maxEqualRows, patternCount.get(key));
        }
        
        return maxEqualRows;
    }
}
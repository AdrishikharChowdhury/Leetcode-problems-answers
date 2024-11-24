class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int n = matrix.length;
        long sum = 0;
        int minAbs = Integer.MAX_VALUE;
        int countNegative = 0;
        
        // Count negative numbers and find minimum absolute value
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) {
                    countNegative++;
                }
                minAbs = Math.min(minAbs, Math.abs(matrix[i][j]));
                sum += Math.abs(matrix[i][j]);
            }
        }
        
        // If count of negative numbers is even, all numbers can be made positive
        // If odd, we need to keep the smallest absolute value negative
        if (countNegative % 2 == 1) {
            sum -= 2L * minAbs;
        }
        
        return sum;
    }
}
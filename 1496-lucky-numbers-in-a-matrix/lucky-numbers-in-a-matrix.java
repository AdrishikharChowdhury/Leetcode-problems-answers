class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        int m = matrix.length;
        int n = matrix[0].length;

        for (int i = 0; i < m; i++) {
            int minInRow = matrix[i][0];
            int minColIndex = 0;

            // Find minimum in row
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] < minInRow) {
                    minInRow = matrix[i][j];
                    minColIndex = j;
                }
            }

            // Check if it's maximum in its column
            boolean isMaxInCol = true;
            for (int k = 0; k < m; k++) {
                if (matrix[k][minColIndex] > minInRow) {
                    isMaxInCol = false;
                    break;
                }
            }

            if (isMaxInCol) {
                result.add(minInRow);
            }
        }

        return result;
    }
}
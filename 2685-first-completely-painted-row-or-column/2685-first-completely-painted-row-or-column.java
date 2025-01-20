class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        
        // Map to store number -> cell position mapping
        int[] numToRow = new int[m * n + 1];
        int[] numToCol = new int[m * n + 1];
        
        // Store positions of each number in mat
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num = mat[i][j];
                numToRow[num] = i;
                numToCol[num] = j;
            }
        }
        
        // Track count of painted cells in each row and column
        int[] rowCount = new int[m];
        int[] colCount = new int[n];
        
        // Process each number in arr
        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            int row = numToRow[num];
            int col = numToCol[num];
            
            rowCount[row]++;
            colCount[col]++;
            
            // Check if current row or column is completely painted
            if (rowCount[row] == n || colCount[col] == m) {
                return i;
            }
        }
        
        return arr.length - 1; // This line should never be reached given constraints
    }
}
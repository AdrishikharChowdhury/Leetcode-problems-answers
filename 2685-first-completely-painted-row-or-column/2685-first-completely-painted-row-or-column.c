int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize) {
    int m = matSize;
    int n = matColSize[0];
    
    // Arrays to store number -> cell position mapping
    int* numToRow = (int*)calloc(m * n + 1, sizeof(int));
    int* numToCol = (int*)calloc(m * n + 1, sizeof(int));
    
    // Store positions of each number in mat
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = mat[i][j];
            numToRow[num] = i;
            numToCol[num] = j;
        }
    }
    
    // Track count of painted cells in each row and column
    int* rowCount = (int*)calloc(m, sizeof(int));
    int* colCount = (int*)calloc(n, sizeof(int));
    
    // Process each number in arr
    for (int i = 0; i < arrSize; i++) {
        int num = arr[i];
        int row = numToRow[num];
        int col = numToCol[num];
        
        rowCount[row]++;
        colCount[col]++;
        
        // Check if current row or column is completely painted
        if (rowCount[row] == n || colCount[col] == m) {
            // Free allocated memory before returning
            free(numToRow);
            free(numToCol);
            free(rowCount);
            free(colCount);
            return i;
        }
    }
    
    // Free allocated memory
    free(numToRow);
    free(numToCol);
    free(rowCount);
    free(colCount);
    
    return arrSize - 1; // This line should never be reached given constraints
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
     int m = matrixSize;
    int n = matrixColSize[0];
    int* result = malloc(sizeof(int) * (m < n ? m : n)); // At most min(m,n) lucky numbers
    *returnSize = 0;

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
        int isMaxInCol = 1;
        for (int k = 0; k < m; k++) {
            if (matrix[k][minColIndex] > minInRow) {
                isMaxInCol = 0;
                break;
            }
        }

        if (isMaxInCol) {
            result[(*returnSize)++] = minInRow;
        }
    }

    return result;
}
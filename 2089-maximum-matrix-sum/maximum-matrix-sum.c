#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    long long sum = 0;
    int minAbs = INT_MAX;
    int countNegative = 0;
    
    // Count negative numbers and find minimum absolute value
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 0) {
                countNegative++;
            }
            minAbs = MIN(minAbs, ABS(matrix[i][j]));
            sum += ABS(matrix[i][j]);
        }
    }
    
    // If count of negative numbers is odd, 
    // we need to keep the smallest absolute value negative
    if (countNegative % 2 == 1) {
        sum -= 2LL * minAbs;
    }
    
    return sum;
}
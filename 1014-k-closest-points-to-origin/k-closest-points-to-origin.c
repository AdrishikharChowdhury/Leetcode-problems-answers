/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    int* point1 = *(int**)a;
    int* point2 = *(int**)b;
    return (point1[0] * point1[0] + point1[1] * point1[1]) - 
           (point2[0] * point2[0] + point2[1] * point2[1]);
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    qsort(points, pointsSize, sizeof(int*), compare);
    
    *returnSize = k;
    *returnColumnSizes = (int*)malloc(k * sizeof(int));
    int** result = (int**)malloc(k * sizeof(int*));
    
    for (int i = 0; i < k; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        result[i][0] = points[i][0];
        result[i][1] = points[i][1];
        (*returnColumnSizes)[i] = 2;
    }
    
    return result;
}
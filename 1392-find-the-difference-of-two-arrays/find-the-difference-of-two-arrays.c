/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    int* set1 = (int*)calloc(2001, sizeof(int));
    int* set2 = (int*)calloc(2001, sizeof(int));
    
    for (int i = 0; i < nums1Size; i++) {
        set1[nums1[i] + 1000] = 1;
    }
    for (int i = 0; i < nums2Size; i++) {
        set2[nums2[i] + 1000] = 1;
    }
    
    int** result = (int**)malloc(2 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    result[0] = (int*)malloc(2001 * sizeof(int));
    result[1] = (int*)malloc(2001 * sizeof(int));
    
    int count1 = 0, count2 = 0;
    
    for (int i = 0; i < 2001; i++) {
        if (set1[i] && !set2[i]) {
            result[0][count1++] = i - 1000;
        }
        if (set2[i] && !set1[i]) {
            result[1][count2++] = i - 1000;
        }
    }
    
    (*returnColumnSizes)[0] = count1;
    (*returnColumnSizes)[1] = count2;
    
    free(set1);
    free(set2);
    
    return result;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    // Initialize result array with 1s
    for (int i = 0; i < numsSize; i++) {
        result[i] = 1;
    }

    // Calculate left products
    int leftProduct = 1;
    for (int i = 0; i < numsSize; i++) {
        result[i] *= leftProduct;
        leftProduct *= nums[i];
    }

    // Calculate right products and combine with left products
    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return result;
}
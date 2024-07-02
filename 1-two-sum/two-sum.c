/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Create an array to store the result indices
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // Iterate through the array
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            // Check if the current pair sums up to the target
            if (nums[i] + nums[j] == target) {
                // Store the indices in the result array and return
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    // If no solution is found (which should not happen as per the problem statement)
    return NULL;
}
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

int main() {
    int numsSize, target;
    
    // Get array size from user
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);
    
    // Allocate memory for the array
    int* nums = (int*)malloc(numsSize * sizeof(int));
    
    // Get array elements from user
    printf("Enter %d integers for the array:\n", numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    
    // Get target sum from user
    printf("Enter the target sum: ");
    scanf("%d", &target);
    
    int returnSize;
    int* indices = twoSum(nums, numsSize, target, &returnSize);
    
    if (indices != NULL) {
        printf("Output: [%d, %d]\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No two elements add up to the target.\n");
    }
    
    free(nums);  // Free dynamically allocated array
    return 0;
}
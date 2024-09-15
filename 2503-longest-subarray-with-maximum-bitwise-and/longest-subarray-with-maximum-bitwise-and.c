#include <stdio.h>

int longestSubarray(int* nums, int numsSize) {
    int maxNum = 0;
    int i;
    
    // Find the maximum number in the array
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > maxNum) {
            maxNum = nums[i];
        }
    }
    
    int currentLength = 0;
    int maxLength = 0;
    
    // Find the longest consecutive sequence of maxNum
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == maxNum) {
            currentLength++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        } else {
            currentLength = 0;
        }
    }
    
    return maxLength;
}
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int countPairs(int* nums, int numsSize, int distance) {
    int count = 0;
    int left = 0;
    
    for (int right = 0; right < numsSize; right++) {
        while (nums[right] - nums[left] > distance) {
            left++;
        }
        count += right - left;
    }
    
    return count;
}

int smallestDistancePair(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int left = 0;
    int right = nums[numsSize - 1] - nums[0];
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = countPairs(nums, numsSize, mid);
        
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}
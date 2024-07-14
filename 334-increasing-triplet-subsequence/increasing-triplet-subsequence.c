#include <stdbool.h>
#include <limits.h>

bool increasingTriplet(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 3) {
        return false;
    }
    
    int first = INT_MAX;
    int second = INT_MAX;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= first) {
            first = nums[i];
        } else if (nums[i] <= second) {
            second = nums[i];
        } else {
            return true;
        }
    }
    
    return false;
}
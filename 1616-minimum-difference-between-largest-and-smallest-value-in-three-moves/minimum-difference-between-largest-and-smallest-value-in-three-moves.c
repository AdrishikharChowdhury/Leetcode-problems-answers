#include <limits.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int minDifference(int* nums, int numsSize) {
    int n = numsSize;
    if (n < 5) return 0;

    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;

    for (int i = 0; i < n; i++) {
        // Update minimums
        if (nums[i] <= min1) {
            min4 = min3; min3 = min2; min2 = min1; min1 = nums[i];
        } else if (nums[i] <= min2) {
            min4 = min3; min3 = min2; min2 = nums[i];
        } else if (nums[i] <= min3) {
            min4 = min3; min3 = nums[i];
        } else if (nums[i] < min4) {
            min4 = nums[i];
        }

        // Update maximums
        if (nums[i] >= max1) {
            max4 = max3; max3 = max2; max2 = max1; max1 = nums[i];
        } else if (nums[i] >= max2) {
            max4 = max3; max3 = max2; max2 = nums[i];
        } else if (nums[i] >= max3) {
            max4 = max3; max3 = nums[i];
        } else if (nums[i] > max4) {
            max4 = nums[i];
        }
    }

    int ans = INT_MAX;
    ans = MIN(ans, max4 - min1); // Change 3 largest
    ans = MIN(ans, max3 - min2); // Change 2 largest and 1 smallest
    ans = MIN(ans, max2 - min3); // Change 1 largest and 2 smallest
    ans = MIN(ans, max1 - min4); // Change 3 smallest

    return ans;
}
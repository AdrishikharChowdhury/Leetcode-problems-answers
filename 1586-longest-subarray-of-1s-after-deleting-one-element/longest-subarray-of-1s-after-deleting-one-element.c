#define MAX(a,b) ((a) > (b) ? (a) : (b))

int longestSubarray(int* nums, int numsSize) {
    int left = 0, right;
    int zeroCount = 0;
    int maxLength = 0;
    
    for (right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            zeroCount++;
        }
        
        while (zeroCount > 1) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }
        
        maxLength = MAX(maxLength, right - left);
    }
    
    return maxLength;
}
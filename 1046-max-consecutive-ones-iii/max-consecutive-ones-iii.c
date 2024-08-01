#define MAX(a,b) ((a) > (b) ? (a) : (b))

int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, right;
    int maxOnes = 0;
    int zeroCount = 0;
    
    for (right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            zeroCount++;
        }
        
        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }
        
        maxOnes = MAX(maxOnes, right - left + 1);
    }
    
    return maxOnes;
}
void moveZeroes(int* nums, int numsSize) {
    int nonZeroIndex = 0;
    
    // Move all non-zero elements to the front
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[nonZeroIndex] = nums[i];
            nonZeroIndex++;
        }
    }
    
    // Fill the rest with zeroes
    while (nonZeroIndex < numsSize) {
        nums[nonZeroIndex] = 0;
        nonZeroIndex++;
    }
}
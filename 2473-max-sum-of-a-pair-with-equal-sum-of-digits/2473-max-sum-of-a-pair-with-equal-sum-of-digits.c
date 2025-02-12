int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int maximumSum(int* nums, int numsSize) {
    // Array to store the largest and second largest numbers for each digit sum
    // Index is digit sum (0-90), each element has two values [max1, max2]
    int digitSums[91][2] = {0};  // Max digit sum is 9*10=90 for 10^9
    
    // Initialize all values to -1
    for (int i = 0; i < 91; i++) {
        digitSums[i][0] = -1;
        digitSums[i][1] = -1;
    }
    
    int maxPairSum = -1;
    
    // Process each number
    for (int i = 0; i < numsSize; i++) {
        int sum = getDigitSum(nums[i]);
        
        // Update the two maximum values for this digit sum
        if (nums[i] > digitSums[sum][0]) {
            digitSums[sum][1] = digitSums[sum][0];
            digitSums[sum][0] = nums[i];
        } else if (nums[i] > digitSums[sum][1]) {
            digitSums[sum][1] = nums[i];
        }
    }
    
    // Find maximum pair sum
    for (int sum = 0; sum < 91; sum++) {
        if (digitSums[sum][0] != -1 && digitSums[sum][1] != -1) {
            int pairSum = digitSums[sum][0] + digitSums[sum][1];
            if (pairSum > maxPairSum) {
                maxPairSum = pairSum;
            }
        }
    }
    
    return maxPairSum;
}
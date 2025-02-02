bool check(int* nums, int numsSize) {
    // Count the number of times adjacent elements decrease
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // Compare current element with next element
        // For last element, compare with first element using modulo
        if (nums[i] > nums[(i + 1) % numsSize]) {
            count++;
        }
        
        // If we find more than one decrease, it's impossible
        if (count > 1) {
            return false;
        }
    }
    
    return true;
}
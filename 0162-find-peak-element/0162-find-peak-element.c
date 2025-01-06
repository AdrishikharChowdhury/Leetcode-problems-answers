int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // If mid element is smaller than next element,
        // peak must be on the right side
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            // Peak could be mid or on left side
            right = mid;
        }
    }
    
    return left;  // or right, they're equal at this point
}
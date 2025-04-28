long long countSubarrays(int* nums, int numsSize, long long k) {
    long long count = 0;
    long long sum = 0;
    int left = 0;
    
    for (int right = 0; right < numsSize; right++) {
        // Add current element to sum
        sum += nums[right];
        
        // Calculate current window score
        long long score = sum * (right - left + 1);
        
        // Shrink window from left while score is too large
        while (left <= right && score >= k) {
            sum -= nums[left];
            left++;
            // Recalculate score after shrinking
            score = sum * (right - left + 1);
        }
        
        // Add count of all valid subarrays ending at right
        count += (right - left + 1);
    }
    
    return count;
}
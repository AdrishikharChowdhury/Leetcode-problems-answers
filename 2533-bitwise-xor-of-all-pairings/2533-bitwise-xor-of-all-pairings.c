int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int result = 0;
    
    // If nums2Size is odd, each number in nums1 appears odd times in final result
    if (nums2Size & 1) {
        for (int i = 0; i < nums1Size; i++) {
            result ^= nums1[i];
        }
    }
    
    // If nums1Size is odd, each number in nums2 appears odd times in final result
    if (nums1Size & 1) {
        for (int i = 0; i < nums2Size; i++) {
            result ^= nums2[i];
        }
    }
    
    return result;
}
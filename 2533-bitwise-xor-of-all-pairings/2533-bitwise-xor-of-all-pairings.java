class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int result = 0;
        int n1 = nums1.length;
        int n2 = nums2.length;
        
        // If nums2.length is odd, each number in nums1 appears odd times in final result
        if ((n2 & 1) == 1) {
            for (int num : nums1) {
                result ^= num;
            }
        }
        
        // If nums1.length is odd, each number in nums2 appears odd times in final result
        if ((n1 & 1) == 1) {
            for (int num : nums2) {
                result ^= num;
            }
        }
        
        return result;
    }
}
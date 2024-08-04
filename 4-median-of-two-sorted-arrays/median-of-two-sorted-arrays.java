class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int[] merged = new int[m + n];
        
        int i = 0, j = 0, k = 0;
        
        // Merge the two sorted arrays
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }
        
        // Add remaining elements from nums1, if any
        while (i < m) {
            merged[k++] = nums1[i++];
        }
        
        // Add remaining elements from nums2, if any
        while (j < n) {
            merged[k++] = nums2[j++];
        }
        
        int totalLength = m + n;
        if (totalLength % 2 == 0) {
            // If even number of elements, return average of two middle elements
            return (merged[totalLength/2 - 1] + merged[totalLength/2]) / 2.0;
        } else {
            // If odd number of elements, return the middle element
            return merged[totalLength/2];
        }
    }
}
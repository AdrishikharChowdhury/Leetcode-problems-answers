double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int* merged = (int*)malloc(totalSize * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Merge the two sorted arrays
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }

    // Add remaining elements from nums1, if any
    while (i < nums1Size) {
        merged[k++] = nums1[i++];
    }

    // Add remaining elements from nums2, if any
    while (j < nums2Size) {
        merged[k++] = nums2[j++];
    }

    double median;
    if (totalSize % 2 == 0) {
        median = (merged[totalSize/2 - 1] + merged[totalSize/2]) / 2.0;
    } else {
        median = merged[totalSize/2];
    }

    free(merged);
    return median;
}
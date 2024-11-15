class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length;
        int left = 0;
        
        // Find longest non-decreasing prefix
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        // If array is already sorted
        if (left == n - 1) return 0;
        
        // Find longest non-decreasing suffix
        int right = n - 1;
        while (right > left && arr[right - 1] <= arr[right]) {
            right--;
        }
        
        // Initial result: remove everything between left and right
        int result = Math.min(n - left - 1, right);
        
        // Try to merge prefix and suffix
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = Math.min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
}
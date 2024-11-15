int findLengthOfShortestSubarray(int* arr, int arrSize) {
    int left = 0;
    
    // Find longest non-decreasing prefix
    while (left + 1 < arrSize && arr[left] <= arr[left + 1]) {
        left++;
    }
    
    // If array is already sorted
    if (left == arrSize - 1) return 0;
    
    // Find longest non-decreasing suffix
    int right = arrSize - 1;
    while (right > left && arr[right - 1] <= arr[right]) {
        right--;
    }
    
    // Initial result: remove everything between left and right
    int result = (arrSize - left - 1 < right) ? arrSize - left - 1 : right;
    
    // Try to merge prefix and suffix
    int i = 0, j = right;
    while (i <= left && j < arrSize) {
        if (arr[i] <= arr[j]) {
            int current = j - i - 1;
            result = (result < current) ? result : current;
            i++;
        } else {
            j++;
        }
    }
    
    return result;
}
import java.util.Arrays;

public class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length, piv = -1;

        // Step 1: Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                piv = i;
                break;
            }
        }

        // If no pivot is found, reverse the entire array
        if (piv == -1) {
            reverse(nums, 0, n - 1);
            return;
        }

        // Step 2: Find the smallest element greater than nums[piv]
        for (int i = n - 1; i > piv; i--) {
            if (nums[i] > nums[piv]) {
                swap(nums, i, piv);
                break;
            }
        }

        // Step 3: Reverse the suffix
        reverse(nums, piv + 1, n - 1);
    }

    private void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            swap(nums, start++, end--);
        }
    }
}

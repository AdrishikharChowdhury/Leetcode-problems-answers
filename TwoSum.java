import java.util.Scanner;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get array size from user
        System.out.print("Enter the size of the array: ");
        int numsSize = scanner.nextInt();

        // Get array elements from user
        int[] nums = new int[numsSize];
        System.out.println("Enter " + numsSize + " integers for the array:");
        for (int i = 0; i < numsSize; i++) {
            nums[i] = scanner.nextInt();
        }

        // Get target sum from user
        System.out.print("Enter the target sum: ");
        int target = scanner.nextInt();

        Solution solution = new Solution();
        int[] indices = solution.twoSum(nums, target);

        if (indices != null) {
            System.out.println("Output: [" + indices[0] + ", " + indices[1] + "]");
        } else {
            System.out.println("No two elements add up to the target.");
        }

        scanner.close();
    }
}
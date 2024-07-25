class Solution {
    private static final int INSERTION_SORT_THRESHOLD = 10;

    public int[] sortArray(int[] nums) {
        shuffle(nums);
        sort(nums, 0, nums.length - 1);
        return nums;
    }

    private void sort(int[] nums, int low, int high) {
        if (high - low <= INSERTION_SORT_THRESHOLD) {
            insertionSort(nums, low, high);
            return;
        }

        int[] p = partition(nums, low, high);
        sort(nums, low, p[0] - 1);
        sort(nums, p[1] + 1, high);
    }

    private int[] partition(int[] nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1, j = high, p = low - 1, q = high;

        while (true) {
            while (nums[++i] < pivot);
            while (pivot < nums[--j]) if (j == low) break;
            if (i >= j) break;
            swap(nums, i, j);
            if (nums[i] == pivot) swap(nums, ++p, i);
            if (nums[j] == pivot) swap(nums, --q, j);
        }
        swap(nums, i, high);
        j = i - 1;
        for (int k = low; k <= p; k++, j--) swap(nums, k, j);
        i = i + 1;
        for (int k = high - 1; k >= q; k--, i++) swap(nums, k, i);
        return new int[]{j + 1, i - 1};
    }

    private void insertionSort(int[] nums, int low, int high) {
        for (int i = low + 1; i <= high; i++) {
            int key = nums[i];
            int j = i - 1;
            while (j >= low && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }
    }

    private void shuffle(int[] nums) {
        Random rand = new Random();
        for (int i = nums.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);
            swap(nums, i, j);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
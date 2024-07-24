import java.util.*;

class Solution {
    private long getMappedValue(int num, int[] mapping) {
        if (num == 0) return mapping[0];
        long mappedValue = 0;
        long multiplier = 1;
        while (num > 0) {
            int digit = num % 10;
            mappedValue += (long)mapping[digit] * multiplier;
            multiplier *= 10;
            num /= 10;
        }
        return mappedValue;
    }

    public int[] sortJumbled(int[] mapping, int[] nums) {
        Integer[] indices = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            indices[i] = i;
        }

        Arrays.sort(indices, (a, b) -> {
            long mappedA = getMappedValue(nums[a], mapping);
            long mappedB = getMappedValue(nums[b], mapping);
            if (mappedA != mappedB) {
                return Long.compare(mappedA, mappedB);
            }
            return a - b;  // Maintain original order for equal mapped values
        });

        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            result[i] = nums[indices[i]];
        }
        return result;
    }
}
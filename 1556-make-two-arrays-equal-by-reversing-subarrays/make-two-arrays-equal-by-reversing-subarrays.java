class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        // Create an array to count the frequency of each number
        int[] count = new int[1001];  // Since 1 <= target[i], arr[i] <= 1000
        
        // Count the frequency of numbers in target (add) and arr (subtract)
        for (int i = 0; i < target.length; i++) {
            count[target[i]]++;
            count[arr[i]]--;
        }
        
        // Check if all frequencies are zero
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }
        
        return true;
    }
}
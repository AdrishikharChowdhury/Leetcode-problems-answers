class Solution {
    private int sumDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    public int getLucky(String s, int k) {
        int sum = 0;
        
        // Convert step and first transform
        for (char c : s.toCharArray()) {
            int value = c - 'a' + 1;
            sum += (value / 10) + (value % 10);  // Directly sum the digits
        }
        
        // Remaining transforms
        for (int i = 1; i < k; i++) {
            sum = sumDigits(sum);
        }
        
        return sum;
    }
}
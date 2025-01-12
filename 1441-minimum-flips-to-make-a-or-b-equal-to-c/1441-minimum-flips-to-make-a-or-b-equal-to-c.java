class Solution {
    public int minFlips(int a, int b, int c) {
        int flips = 0;
        
        // Check each bit position
        while (a > 0 || b > 0 || c > 0) {
            // Get last bits
            int bit_a = a & 1;
            int bit_b = b & 1;
            int bit_c = c & 1;
            
            // If target bit is 1
            if (bit_c == 1) {
                // If both a and b bits are 0, need one flip
                if (bit_a == 0 && bit_b == 0) {
                    flips++;
                }
            } else {
                // If target bit is 0, need to flip all 1s to 0
                flips += bit_a + bit_b;
            }
            
            // Right shift all numbers
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return flips;
    }
}
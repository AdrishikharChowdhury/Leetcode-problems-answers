class Solution {
    public String gcdOfStrings(String str1, String str2) {
        // Check if concatenation in both orders is the same
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        
        // Find GCD of lengths
        int gcdLength = gcd(str1.length(), str2.length());
        
        // Return the substring of length GCD
        return str1.substring(0, gcdLength);
    }
    
    // Helper method to calculate GCD using Euclidean algorithm
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
import java.util.ArrayList;
import java.util.List;

class Solution {
    public String nearestPalindromic(String n) {
        long num = Long.parseLong(n);
        int len = n.length();
        
        // Handle single-digit numbers separately
        if (len == 1) return String.valueOf(num - 1);
        
        // Edge cases for numbers 1, 10, 100, etc.
        if (isPowerOfTen(num)) return String.valueOf(num - 1);
        if (isPowerOfTen(num + 1)) return String.valueOf(num + 2);
        
        // Generate candidates
        List<Long> candidates = new ArrayList<>();
        candidates.add(generatePalindromeByAdding1s(len));
        candidates.add(generatePalindromeBySubtracting1s(len));
        
        long prefix = Long.parseLong(n.substring(0, (len + 1) / 2));
        for (long i = prefix - 1; i <= prefix + 1; i++) {
            candidates.add(generatePalindrome(i, len % 2 == 0));
        }
        
        long closest = getClosest(num, candidates);
        return String.valueOf(closest);
    }
    
    private boolean isPowerOfTen(long num) {
        while (num > 1 && num % 10 == 0) {
            num /= 10;
        }
        return num == 1;
    }
    
    private long generatePalindromeByAdding1s(int len) {
        return (long)Math.pow(10, len) + 1;
    }
    
    private long generatePalindromeBySubtracting1s(int len) {
        return (long)Math.pow(10, len - 1) - 1;
    }
    
    private long generatePalindrome(long prefix, boolean isEven) {
        StringBuilder sb = new StringBuilder(Long.toString(prefix));
        if (!isEven) sb.setLength(sb.length() - 1);
        return Long.parseLong(sb.append(new StringBuilder(Long.toString(prefix)).reverse()).toString());
    }
    
    private long getClosest(long num, List<Long> candidates) {
        long closest = 0;
        long minDiff = Long.MAX_VALUE;
        for (long candidate : candidates) {
            if (candidate == num) continue;
            long diff = Math.abs(candidate - num);
            if (diff < minDiff || (diff == minDiff && candidate < closest)) {
                closest = candidate;
                minDiff = diff;
            }
        }
        return closest;
    }
}

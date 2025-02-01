class Solution {
    public boolean isAlphaNum(char ch) {
        return Character.isLetterOrDigit(ch);
    }

    public boolean isPalindrome(String s) {
        int st = 0, end = s.length() - 1;
        
        while (st < end) {
            while (st < end && !isAlphaNum(s.charAt(st))) {
                st++;
            }
            while (st < end && !isAlphaNum(s.charAt(end))) {
                end--;
            }
            if (Character.toLowerCase(s.charAt(st)) != Character.toLowerCase(s.charAt(end))) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
}

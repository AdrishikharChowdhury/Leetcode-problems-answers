class Solution {
    public int maximumGain(String s, int x, int y) {
        StringBuilder sb = new StringBuilder(s);
        char first = x > y ? 'a' : 'b';
        char second = x > y ? 'b' : 'a';
        int high = Math.max(x, y);
        int low = Math.min(x, y);
        
        int score = removePatterns(sb, first, second, high);
        score += removePatterns(sb, second, first, low);
        
        return score;
    }
    
    private int removePatterns(StringBuilder sb, char first, char second, int points) {
        int score = 0;
        StringBuilder stack = new StringBuilder();
        
        for (int i = 0; i < sb.length(); i++) {
            if (!stack.isEmpty() && sb.charAt(i) == second && stack.charAt(stack.length() - 1) == first) {
                stack.setLength(stack.length() - 1);
                score += points;
            } else {
                stack.append(sb.charAt(i));
            }
        }
        
        sb.setLength(0);
        sb.append(stack);
        return score;
    }
}
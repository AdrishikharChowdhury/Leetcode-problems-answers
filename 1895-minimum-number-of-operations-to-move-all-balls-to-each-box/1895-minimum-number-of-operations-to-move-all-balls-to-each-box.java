class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] answer = new int[n];
        
        // Count balls and moves from left to right
        int ballsOnLeft = 0;
        int movesCumulative = 0;
        
        for (int i = 0; i < n; i++) {
            answer[i] = movesCumulative;
            if (boxes.charAt(i) == '1') {
                ballsOnLeft++;
            }
            movesCumulative += ballsOnLeft;
        }
        
        // Count balls and moves from right to left
        int ballsOnRight = 0;
        movesCumulative = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            answer[i] += movesCumulative;
            if (boxes.charAt(i) == '1') {
                ballsOnRight++;
            }
            movesCumulative += ballsOnRight;
        }
        
        return answer;
    }
}
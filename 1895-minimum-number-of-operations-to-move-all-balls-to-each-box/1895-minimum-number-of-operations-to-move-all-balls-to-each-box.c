int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);
    *returnSize = n;
    int* answer = (int*)calloc(n, sizeof(int));
    
    // Count balls and moves from left to right
    int ballsOnLeft = 0;
    int movesCumulative = 0;
    
    for (int i = 0; i < n; i++) {
        answer[i] = movesCumulative;
        if (boxes[i] == '1') {
            ballsOnLeft++;
        }
        movesCumulative += ballsOnLeft;
    }
    
    // Count balls and moves from right to left
    int ballsOnRight = 0;
    movesCumulative = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        answer[i] += movesCumulative;
        if (boxes[i] == '1') {
            ballsOnRight++;
        }
        movesCumulative += ballsOnRight;
    }
    
    return answer;
}
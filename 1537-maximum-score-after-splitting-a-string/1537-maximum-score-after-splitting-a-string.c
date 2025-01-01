int maxScore(char* s) {
    int maxScore = 0;
    int zeros = 0;
    int ones = 0;
    int len = strlen(s);
    
    // Count total ones first
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') ones++;
    }
    
    // Try each split position except the last one
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == '0') {
            zeros++;
        } else {
            ones--;
        }
        
        int currentScore = zeros + ones;
        if (currentScore > maxScore) {
            maxScore = currentScore;
        }
    }
    
    return maxScore;
}
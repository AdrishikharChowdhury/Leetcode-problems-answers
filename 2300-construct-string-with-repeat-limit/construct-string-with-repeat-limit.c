char* repeatLimitedString(char* s, int repeatLimit) {
    // Count character frequencies
    int count[26] = {0};
    int len = strlen(s);
    
    // Count frequencies
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }
    
    // Allocate result string (maximum possible length)
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int resultIndex = 0;
    result[0] = '\0';
    
    // Process from largest to smallest character
    for (int i = 25; i >= 0; ) {
        // Skip if current character is exhausted
        if (count[i] == 0) {
            i--;
            continue;
        }
        
        // Count consecutive characters at the end of result
        int consecutiveCount = 0;
        if (resultIndex > 0) {
            for (int j = resultIndex - 1; j >= 0 && result[j] == (char)(i + 'a'); j--) {
                consecutiveCount++;
            }
        }
        
        // Determine how many characters we can add
        int toAdd = (consecutiveCount < repeatLimit) ? 
            (consecutiveCount == 0 ? 
                (count[i] < repeatLimit ? count[i] : repeatLimit) : 
                (repeatLimit - consecutiveCount)) : 0;
        
        // Add characters
        for (int j = 0; j < toAdd; j++) {
            result[resultIndex++] = (char)(i + 'a');
            count[i]--;
        }
        result[resultIndex] = '\0';
        
        // If all of current character used, move to next
        if (count[i] == 0) {
            i--;
            continue;
        }
        
        // Find next smaller character to break sequence
        int j = i - 1;
        while (j >= 0 && count[j] == 0) {
            j--;
        }
        
        // If no smaller character, we're done
        if (j < 0) {
            break;
        }
        
        // Add one character from next smaller character
        result[resultIndex++] = (char)(j + 'a');
        result[resultIndex] = '\0';
        count[j]--;
        
        // If no more of this character, move to next
        if (count[j] == 0) {
            j--;
        }
        
        // Reset where we're looking
        i = (i > j) ? i : j;
    }
    
    return result;
}
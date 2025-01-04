int countPalindromicSubsequence(char* s) {
    int len = strlen(s);
    
    // Store first and last occurrence of each character
    int firstOccurrence[26];
    int lastOccurrence[26];
    memset(firstOccurrence, -1, sizeof(firstOccurrence));
    memset(lastOccurrence, -1, sizeof(lastOccurrence));
    
    // Find first and last occurrence of each character
    for (int i = 0; i < len; i++) {
        int charIndex = s[i] - 'a';
        if (firstOccurrence[charIndex] == -1) {
            firstOccurrence[charIndex] = i;
        }
        lastOccurrence[charIndex] = i;
    }
    
    int count = 0;
    // For each character as first and last character of palindrome
    for (int i = 0; i < 26; i++) {
        // If character appears at least twice
        if (firstOccurrence[i] != -1 && lastOccurrence[i] > firstOccurrence[i]) {
            // Use boolean array to track unique middle characters
            bool middle[26] = {false};
            for (int j = firstOccurrence[i] + 1; j < lastOccurrence[i]; j++) {
                middle[s[j] - 'a'] = true;
            }
            // Count unique middle characters
            for (int j = 0; j < 26; j++) {
                if (middle[j]) {
                    count++;
                }
            }
        }
    }
    
    return count;
}
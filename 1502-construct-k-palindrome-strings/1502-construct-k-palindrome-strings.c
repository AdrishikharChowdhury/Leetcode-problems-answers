bool canConstruct(char* s, int k) {
    // Count frequency of each character
    int freq[26] = {0};
    int len = strlen(s);
    
    // If k is greater than string length, impossible
    if (k > len) return false;
    
    // Count frequencies
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    
    // Count characters with odd frequency
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            oddCount++;
        }
    }
    
    // If odd count is greater than k, impossible
    // If k is greater than length, impossible
    // Otherwise, it's possible
    return oddCount <= k && k <= len;
}
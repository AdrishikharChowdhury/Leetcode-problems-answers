int lengthOfLongestSubstring(char * s) {
    int n = strlen(s);
    int maxLen = 0;
    int start = 0;
    int index[128]; // Assuming ASCII characters

    for (int i = 0; i < 128; i++) {
        index[i] = -1; // Initialize index of characters as -1
    }

    for (int end = 0; end < n; end++) {
        char currentChar = s[end];
        if (index[(int)currentChar] >= start) {
            start = index[(int)currentChar] + 1;
        }
        index[(int)currentChar] = end;
        maxLen = (maxLen > (end - start + 1)) ? maxLen : (end - start + 1);
    }

    return maxLen;
}

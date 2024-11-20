int takeCharacters(char* s, int k) {
    int len = strlen(s);
    
    // If k is 0, no minutes needed
    if (k == 0) return 0;
    
    // Count total occurrences of a, b, c
    int total[3] = {0};
    for (int i = 0; i < len; i++) {
        total[s[i] - 'a']++;
    }
    
    // If not enough characters
    if (total[0] < k || total[1] < k || total[2] < k) {
        return -1;
    }
    
    // Sliding window to find minimum subarray to remove
    int need[3] = {total[0] - k, total[1] - k, total[2] - k};
    int left = 0, max_removed = -1;
    int curr[3] = {0};
    
    for (int right = 0; right < len; right++) {
        // Add current character to window
        curr[s[right] - 'a']++;
        
        // Shrink window from left if needed
        while (curr[0] > need[0] || curr[1] > need[1] || curr[2] > need[2]) {
            curr[s[left] - 'a']--;
            left++;
        }
        
        // Update max removed subarray
        max_removed = fmax(max_removed, right - left + 1);
    }
    
    // Total minutes is total length minus max removable subarray
    return len - max_removed;
}
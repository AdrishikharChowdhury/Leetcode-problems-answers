char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int n = strlen(s);
    // Create difference array
    int* diff = (int*)calloc(n + 1, sizeof(int));
    
    // Process all shifts using difference array
    for (int i = 0; i < shiftsSize; i++) {
        int start = shifts[i][0];
        int end = shifts[i][1];
        // Convert 0/1 direction to -1/1
        int direction = shifts[i][2] == 1 ? 1 : -1;
        
        diff[start] += direction;
        diff[end + 1] -= direction;
    }
    
    // Create result string (we'll modify the input string directly)
    char* result = (char*)malloc((n + 1) * sizeof(char));
    strcpy(result, s);
    
    // Calculate prefix sum and apply shifts
    int totalShift = 0;
    for (int i = 0; i < n; i++) {
        totalShift += diff[i];
        // Get original character value (0-25)
        int originalVal = s[i] - 'a';
        // Calculate new value after shift
        int newVal = ((originalVal + totalShift) % 26 + 26) % 26;
        // Convert back to character
        result[i] = newVal + 'a';
    }
    
    free(diff);
    return result;
}
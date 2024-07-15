int compress(char* chars, int charsSize) {
    int writeIndex = 0;
    int readIndex = 0;
    
    while (readIndex < charsSize) {
        char currentChar = chars[readIndex];
        int count = 0;
        
        // Count consecutive repeating characters
        while (readIndex < charsSize && chars[readIndex] == currentChar) {
            readIndex++;
            count++;
        }
        
        // Write character
        chars[writeIndex++] = currentChar;
        
        // Write count if greater than 1
        if (count > 1) {
            int digits = 0;
            int temp = count;
            while (temp > 0) {
                temp /= 10;
                digits++;
            }
            
            int start = writeIndex + digits - 1;
            while (count > 0) {
                chars[start--] = (count % 10) + '0';
                count /= 10;
                writeIndex++;
            }
        }
    }
    
    return writeIndex;
}
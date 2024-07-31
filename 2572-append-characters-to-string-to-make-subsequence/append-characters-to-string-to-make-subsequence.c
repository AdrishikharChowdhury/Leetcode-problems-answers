int appendCharacters(char * s, char * t) {
    int sPointer = 0;
    int tPointer = 0;
    
    while (s[sPointer] != '\0' && t[tPointer] != '\0') {
        if (s[sPointer] == t[tPointer]) {
            tPointer++;
        }
        sPointer++;
    }
    
    return strlen(t) - tPointer;
}
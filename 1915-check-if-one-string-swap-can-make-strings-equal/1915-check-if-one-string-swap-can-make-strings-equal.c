bool areAlmostEqual(char* s1, char* s2) {
    if (strcmp(s1, s2) == 0) return true;
    
    int first = -1, second = -1;
    int mismatches = 0;
    
    for (int i = 0; s1[i]; i++) {
        if (s1[i] != s2[i]) {
            if (mismatches == 0) first = i;
            else if (mismatches == 1) second = i;
            mismatches++;
        }
    }
    
    return mismatches == 2 && 
           s1[first] == s2[second] && 
           s1[second] == s2[first];
}
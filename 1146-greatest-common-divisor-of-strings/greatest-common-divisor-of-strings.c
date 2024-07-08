char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Check if concatenation in both orders is the same
    char* concat1 = malloc(len1 + len2 + 1);
    char* concat2 = malloc(len1 + len2 + 1);
    strcpy(concat1, str1);
    strcat(concat1, str2);
    strcpy(concat2, str2);
    strcat(concat2, str1);
    
    if (strcmp(concat1, concat2) != 0) {
        free(concat1);
        free(concat2);
        return "";
    }
    
    free(concat1);
    free(concat2);
    
    // Find GCD of lengths
    int gcd = len2;
    int temp = len1 % len2;
    while (temp != 0) {
        gcd = temp;
        temp = len2 % gcd;
        len2 = gcd;
    }
    
    // Allocate and return the result
    char* result = malloc(gcd + 1);
    strncpy(result, str1, gcd);
    result[gcd] = '\0';
    
    return result;
}
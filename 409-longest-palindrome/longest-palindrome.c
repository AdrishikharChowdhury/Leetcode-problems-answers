#include <string.h>

int longestPalindrome(char * s) {
    int charCount[128] = {0};  // Assuming ASCII characters
    int length = strlen(s);
    
    for (int i = 0; i < length; i++) {
        charCount[s[i]]++;
    }
    
    int palindromeLength = 0;
    int hasOdd = 0;
    
    for (int i = 0; i < 128; i++) {
        palindromeLength += charCount[i] / 2 * 2;
        if (charCount[i] % 2 == 1) {
            hasOdd = 1;
        }
    }
    
    return palindromeLength + hasOdd;
}
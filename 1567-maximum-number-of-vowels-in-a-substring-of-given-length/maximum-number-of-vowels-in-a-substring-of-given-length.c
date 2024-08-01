#define MAX(a,b) ((a) > (b) ? (a) : (b))

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(char * s, int k){
    int maxVowels = 0;
    int currentVowels = 0;
    int length = strlen(s);
    
    // Count vowels in the first window
    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) {
            currentVowels++;
        }
    }
    maxVowels = currentVowels;
    
    // Slide the window
    for (int i = k; i < length; i++) {
        if (isVowel(s[i - k])) {
            currentVowels--;
        }
        if (isVowel(s[i])) {
            currentVowels++;
        }
        maxVowels = MAX(maxVowels, currentVowels);
    }
    
    return maxVowels;
}
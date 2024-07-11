bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
char* reverseVowels(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    while (left < right) {
        while (left < right && !isVowel(s[left])) {
            left++;
        }
        while (left < right && !isVowel(s[right])) {
            right--;
        }
        if (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    
    return s;
}
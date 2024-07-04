void reverseString(char* s, int sSize) {
    char temp;
    int left=0,right=sSize-1;
    while (left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
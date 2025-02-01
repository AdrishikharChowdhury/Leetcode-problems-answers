void reverseString(char* s, int n) {
    char temp;
    
    for(int i=0;i<n/2;i++)
    {
        temp=s[i];
        s[i]=s[n-1-i];
        s[n-i-1]=temp;
    }
}
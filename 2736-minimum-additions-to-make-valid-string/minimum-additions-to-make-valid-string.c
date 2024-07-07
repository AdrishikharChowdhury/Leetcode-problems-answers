int addMinimum(char * word){
    int a=0,i=0;
    int len=strlen(word);
    char expected='a';
    while (i < len) {
        if (word[i] == expected)
        i++;
        else
        a++;        
        expected++;
        if (expected > 'c') 
        expected = 'a';
    }
    while (expected != 'a') {
        a++;
        expected++;
        if (expected > 'c') 
        expected = 'a';
    }
    
    return a;
}
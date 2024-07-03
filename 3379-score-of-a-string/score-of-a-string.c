int scoreOfString(char* s) {
    int i,sum=0,a1,a2;
    for(i=0;s[i]!='\0' && s[i+1]!='\0';i++)
    {
        a1=(int)s[i];
        a2=(int)s[i+1];
        sum=sum+abs(a1-a2);
    }
    return sum;
}
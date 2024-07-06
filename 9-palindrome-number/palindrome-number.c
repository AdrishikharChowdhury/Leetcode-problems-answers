bool isPalindrome(int x) {
    long long sum=0;
    int num=x,q;
    if (x < 0) 
    return false;
    if (x >= 0 && x < 10) 
    return true;
    while(num!=0)
    {
        q=num%10;
        sum=(10*sum)+q;
        num /= 10;
    }
    if(x==sum)
    return true;
    else
    return false;
}
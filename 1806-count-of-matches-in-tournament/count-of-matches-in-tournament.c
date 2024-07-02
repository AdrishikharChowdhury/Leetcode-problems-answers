

int numberOfMatches(int n){
    int match,round=0;
    while(n>1)
    {
        if(n%2==0)
        {
            match=n/2;
            round=round+match;
            n=n/2;
        }
        else
        {
            match=(n-1)/2;
            round=round+match;
            n=((n-1)/2)+1;
        }
    }
    return round;
}
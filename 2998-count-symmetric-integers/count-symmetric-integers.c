bool Sym(int a)
{
    int *digits,count=0;
    if(a<10)
    {
        free(digits);
        return false;
    }
    digits=(int *)malloc(10*sizeof(int));
    while(a!=0)
    {
        digits[count++]=a%10;
        a/=10;
    }
    if(count%2!=0)
    {
        free(digits);
        return false;
    }
    int hl=count/2;
    int s1=0,s2=0,i;
    for(i=0;i<hl;i++)
    {
        s1+=digits[i];
        s2+=digits[count-1-i];
    }
    free(digits);
    return s1==s2;
}
int countSymmetricIntegers(int low, int high){
    int i,c=0;
    for(i=low;i<=high;i++)
    {
        if(Sym(i))
        c++;
    }
    return c;
}
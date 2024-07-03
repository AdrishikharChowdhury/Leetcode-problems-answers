int subtractProductAndSum(int n) {
    int mult=1,sum=0,q;
    while(n!=0)
    {
        q=n%10;
        mult=mult*q;
        sum=sum+q;
        n=n/10;
    }
    return mult-sum;
}
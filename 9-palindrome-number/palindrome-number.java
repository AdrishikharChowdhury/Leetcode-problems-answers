class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)
        return false;
        else if(x>=0 && x<10)
        return true;
        int sum=0,num=x,q;
        while(num!=0)
        {
            q=num%10;
            sum=q+(10*sum);
            num/=10;
        }
        if(x==sum)
        return true;
        else
        return false;
    }
}
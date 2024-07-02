class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int c=0,n=0;
        for(int num:nums)
        {
           if(num==1)
            {
                c++;
                if(c>n)
                n=c;
            }
            else
            c=0; 
        }
        return n;
    }
}
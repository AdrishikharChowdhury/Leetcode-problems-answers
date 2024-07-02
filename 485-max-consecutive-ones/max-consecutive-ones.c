int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int i,c=0,n=0;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==1)
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
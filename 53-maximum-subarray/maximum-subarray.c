int maximum(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int maxSubArray(int* nums, int numsSize) {
    int maxSum=INT_MIN;
    int currentSum=0;
    for(int i=0;i<numsSize;i++)
    {
        currentSum+=nums[i];
        maxSum=maximum(currentSum,maxSum);
        if(currentSum<0)
        {
            currentSum=0;
        }
    }
    return maxSum;
}
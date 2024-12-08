class Solution {
    public int maxSubArray(int[] nums) {
        int n=nums.length;
        int currentSum=0,maxSum=-999999;
        for(int i=0;i<n;i++)
        {
            currentSum+=nums[i];
            maxSum=max(currentSum,maxSum);
            if(currentSum<0)
            {
                currentSum=0;
            }
        }
        return maxSum;
    }
    public int max(int a,int b)
    {
        if(a>b)
            return a;
        return b;
    }
}
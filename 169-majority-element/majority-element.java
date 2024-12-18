class Solution {
    public int majorityElement(int[] nums) {
    int freq=0,ans=0,i;
    int numsSize=nums.length;
    for(i=0;i<numsSize;i++)
    {
        if(freq==0)
        {
            ans=nums[i];
        }
        if(ans==nums[i])
        {
            freq+=1;
        }
        else
        {
            freq-=1;
        }
    }
    int c=0;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==ans)
        {
            c+=1;
        }
    }
    if(c>numsSize/2)
        return ans;
    else
        return -1;
    }
}
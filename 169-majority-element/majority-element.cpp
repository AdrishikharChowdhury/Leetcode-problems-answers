class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0,ans=0,i,n=nums.size();
    for(i=0;i<n;i++)
    {
        if(freq==0)
        {
            ans=nums[i];
        }
        if(ans==nums[i])
        {
            freq+=1;
        }
        else{
            freq-=1;
        }
    }
    int count=0;
    for(int val:nums)
    {
        if(val==ans)
        count+=1;
    }
    if(count>n/2)
        return ans;
    else
        return -1;
    }
};
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
    return ans;
    }
};
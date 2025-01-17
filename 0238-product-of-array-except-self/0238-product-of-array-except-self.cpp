class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
{
    int i,suffix=1,n=nums.size();
    vector<int> ans(n,1);
    for(i=1;i<n;i++)
    {
        ans[i]=ans[i-1]*nums[i-1];
    }
    for(i=n-2;i>=0;i--)
    {
        suffix*=nums[i+1];
        ans[i]*=suffix;
    }
    return ans;
}
};
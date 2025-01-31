class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i,j,piv=-1;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                piv=i;
                break;
            }
        }
        if(piv==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(i=n-1;i>piv;i--)
        {
            if(nums[i]>nums[piv])
            {
                swap(nums[i],nums[piv]);
                break;
            }
        }
        i=piv+1,j=n-1;
        while(i<=j)
        {
            swap(nums[i],nums[j]);
            i+=1;
            j-=1;
        }
    }
};
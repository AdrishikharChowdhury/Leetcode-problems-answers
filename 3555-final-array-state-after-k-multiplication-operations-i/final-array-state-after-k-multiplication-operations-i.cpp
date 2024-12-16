class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int i=0,idx;
        while(i<k)
        {
            idx=minIdx(nums);
            nums[idx]*=multiplier;
            i+=1;
        }
        return nums;
    }
    int minIdx(vector<int>& nums)
    {
        int min=nums[0],idx=0,i;
        for(i=0;i<nums.size();i++)
        {
            if(min>nums[i])
            {
                min=nums[i];
                idx=i;
            }
        }
        return idx;
    }
};
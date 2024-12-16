class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        int idx,i=0;
        while(i<k)
        {
            idx=minIdx(nums);
            nums[idx]*=multiplier;
            i+=1;
        }
        return nums;
    }
    public int minIdx(int[] nums)
    {
        int min=nums[0],idx=0,i;
        for(i=0;i<nums.length;i++)
        {
            if(min>nums[i])
            {
                min=nums[i];
                idx=i;
            }
        }
        return idx;
    }
}
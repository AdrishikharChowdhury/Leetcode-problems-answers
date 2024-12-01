class Solution {
    public int findFinalValue(int[] nums, int original){
        int og=lin_search(nums,original);
        return og;
    }
    public int lin_search(int[] nums,int original)
    {
        int i;
        boolean flag=false;
        for(i=0;i<nums.length;i++)
        {
            if(nums[i]==original)
                flag=true;
        }
        if(flag)
            return original=lin_search(nums,2*original);
        else
            return original;
    }
}
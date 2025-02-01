class Solution {
    public boolean isArraySpecial(int[] nums) {
        int n=nums.length,i;
        if(n==1)
        {
            return true;
        }
        for(i=0;i<n-1;i++)
        {
            if((nums[i]%2)==(nums[i+1]%2))
            {
                return false;
            }
        }
        return true;
    }
}
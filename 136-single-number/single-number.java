class Solution {
    public int singleNumber(int[] nums) {
    int i,j;
    int numsSize=nums.length;
    boolean isUnique=true;
    for(i=0;i<numsSize;i++)
    {
        isUnique=true;
        for(j=0;j<numsSize;j++)
        {
            if(i!=j && nums[i]==nums[j])
            {
                isUnique=false;
                break;
            }
        }
        if(isUnique)
        {
            break;
        }
    }
    return nums[i];
    }
}
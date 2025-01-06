int singleNumber(int* nums, int numsSize) {
    int i,j;
    bool isUnique=true;
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
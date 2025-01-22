int singleNonDuplicate(int* nums, int numsSize) {
    int mid,st=0,end=numsSize-1,n=numsSize;
        if(n==1)
            return nums[0];
        while(st<=end)
        {
            mid=st+(end-st)/2;
            if(mid==0 && nums[0]!=nums[1])
                return nums[mid];
            if(mid==n-1 && nums[n-1]!=nums[n-2])
                return nums[mid];
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
            if(mid%2==0)
            {
                if(nums[mid-1]==nums[mid])
                {
                    end=mid-1;
                }
                else
                {
                    st=mid+1;
                }
            }
            else
            {
                if(nums[mid-1]==nums[mid])
                {
                    st=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
        }
        return -1;
}
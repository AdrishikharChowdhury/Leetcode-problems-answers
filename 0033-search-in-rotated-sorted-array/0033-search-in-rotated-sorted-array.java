class Solution {
    public int search(int[] nums, int target) {
        int mid,st=0,end=nums.length-1;
        while(st<=end)
        {
            mid=st+(end-st)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[st]<=nums[mid])
            {
                if(nums[st]<=target && target<=nums[mid])
                {
                    end=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[end])
                {
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
}
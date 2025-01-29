class Solution {
    public void sortColors(int[] nums) {
        int mid=0,high=nums.length-1,low=0,temp;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                temp=nums[low];
                nums[low]=nums[mid];
                nums[mid]=temp;
                low+=1;
                mid+=1;
            }
            else if(nums[mid]==1)
            {
                mid+=1;
            }
            else{
                temp=nums[high];
                nums[high]=nums[mid];
                nums[mid]=temp;
                high-=1;
            }
        }
    }
}
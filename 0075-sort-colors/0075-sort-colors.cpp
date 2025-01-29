class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid=0,high=nums.size()-1,low=0;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low+=1;
                mid+=1;
            }
            else if(nums[mid]==1)
            {
                mid+=1;
            }
            else{
                swap(nums[high],nums[mid]);
                high-=1;
            }
        }
    }
};
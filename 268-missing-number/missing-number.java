class Solution {
    public int missingNumber(int[] nums) {
        int arr=0;
        for(int i=0;i<nums.length;i++)
        {
            arr=arr+nums[i];
        }
        int n=nums.length;
        int N=(n*(n+1))/2;
        return N-arr;
    }
}